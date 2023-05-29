#include "serialport.h"

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFF 5


Serialport::Serialport(string port, string filename )
    : _port( port ), _filename( filename )
{

}

void Serialport::connect()
{
    try
    {
        _fd = open( "/dev/cu.usbmodem1401", O_RDWR | O_NOCTTY | O_NDELAY );
        if ( _fd == -1 )
        {
            throw std::runtime_error( "Error opening serial port" );
        }
            
        struct termios options;
        //configure serial port
        if ( tcgetattr( _fd, &options ) != 0 )
        {
            throw std::runtime_error( "Error getting serial port attributes" );
        }

        //set transmitton speed
        if ( cfsetispeed( &options, B9600 ) != 0 || cfsetospeed( &options, B9600 ) != 0)
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
        if ( tcsetattr( _fd, TCSANOW, &options ) != 0)
        {
            throw std::runtime_error( "Error setting setting serial port attributes" );
        }
    }
    catch( const std::exception& e )
    {
        std::cerr << e.what() << '\n';
        disconnect();
        exit(EXIT_FAILURE);
    }
}

void Serialport::disconnect()
{
    if (close(_fd) == -1)
    {
        std::cerr << "Error closing serial port\n";
        exit(EXIT_FAILURE);
    }
}

void Serialport::readSerial(int seconds)
{   
    try
    {   
        
        std::ofstream outputFile( "data.txt" );
        if ( !outputFile.is_open() )
        {
            throw std::runtime_error( "Error opening the file" );
        }

        //read data from serial port
        char buff[ BUFF ];
        unsigned int time = seconds;
        while ( true ) {
            sleep( 1 );
            int n = read( _fd, buff, BUFF );
            if ( n == -1 )
            {
                throw std::runtime_error( "Error reading from serial port" );
            }
            if ( n > 2 ) {   

                outputFile << buff << std::endl;
                printf( "Read %d bytes: %.*s\n", n, n, buff );
            }
            std::cout << "Yoooooo" << std::endl; 
            if (time-- == 0)
            {
                break;
            };

        }
        outputFile.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        disconnect();
        exit(EXIT_FAILURE);
    }
    
}