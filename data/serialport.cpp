#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/wait.h>
#include "serialport.h"

#define BUFF 8


Serialport::Serialport(string port, string filename )
    : _port( port ), _filename( filename )
{
}

void Serialport::connect()
{
    try
    {
        const char *port = _port.c_str();
        _fd = open( port , O_RDWR | O_NOCTTY | O_NDELAY );
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

void Serialport::readSerial( int seconds )
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
        string receivedData;
        unsigned int time = seconds;

        while ( true ) {
            sleep( 1 );
            int bytes_read = read( _fd, buff, BUFF );
            if ( bytes_read == -1 )
            {
                throw std::runtime_error( "Error reading from serial port" );
            }
            if ( bytes_read > 0 ) {  
                receivedData += string(buff, bytes_read);

                size_t found1 = receivedData.find("100"); 
                size_t found2 = receivedData.find("050"); 

                if( found1 != string::npos ){ 
                    outputFile << buff;
                    printf( "Read %d bytes: %.*s\n", bytes_read, bytes_read, buff );
                    receivedData.erase(0, found1 + 1 );
                } else if ( found2 != string::npos ) {
                    outputFile << buff;
                    printf( "Read %d bytes: %.*s\n", bytes_read, bytes_read, buff );
                    receivedData.erase(0, found2 + 1);
                } else {
                    outputFile << "";
                }
            }
            if (time-- == 0)
            {
                break;
            }
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
