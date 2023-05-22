#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/wait.h>

#define BDRATE  B9600
#define BUFSIZE 5

int main()
{
    try
    {
        int fd = open( "/dev/cu.usbmodem1101", O_RDWR | O_NOCTTY | O_NDELAY );
        if ( fd == -1 )
        {
            throw std::runtime_error( "Error opening serial port" );
        }
            
        struct termios options;
        //configure serial port
        if ( tcgetattr( fd, &options ) != 0 )
        {
            throw std::runtime_error( "Error getting serial port attributes" );
        }

        //set transmitton speed
        if ( cfsetispeed( &options, BDRATE ) != 0 || cfsetospeed( &options, BDRATE ) != 0)
        {
            throw std::runtime_error( "Error setting serial port baud rate" );
        }

        //set serial port flags
        options.c_cflag |= ( CLOCAL | CREAD );
        options.c_cflag &= ~PARENB;
        options.c_cflag &= ~CSTOPB;
        options.c_cflag &= ~CSIZE;
        options.c_cflag |= CS8;
        options.c_iflag &= ~( IXON | IXOFF | IXANY );
        options.c_oflag &= ~OPOST;
        options.c_lflag &= ~( ICANON | ECHO | ECHOE | ISIG );

        //set above options now
        if ( tcsetattr( fd, TCSANOW, &options ) != 0)
        {
            throw std::runtime_error( "Error setting setting serial port attributes" );
        }

        //open destination file
        std::ofstream outputFile( "data.txt" );
        if ( !outputFile.is_open() )
        {
            throw std::runtime_error( "Error opening the file" );
        }

        //read data from serial port
        char buff[ BUFSIZE ];
        while ( 1 ) {
            sleep( 1 );
            int n = read( fd, buff, BUFSIZE );
            if (n == -1)
            {
                throw std::runtime_error( "Error reading from serial port" );
            }
            if (n > 0) {
                outputFile << buff << std::endl;
                printf( "Read %d bytes: %.*s\n", n, n, buff );
            }
        }
        outputFile.close();
        close( fd );
    }
    catch( const std::exception& e )
    {
        std::cerr << e.what() << '\n';
    }
}
