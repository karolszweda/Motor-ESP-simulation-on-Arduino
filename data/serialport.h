#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <iostream>
#include <string>

using namespace std;

class Serialport {

public:
Serialport( string, string);

void connect();

void disconnect();

void readSerial( int );

private:
string _port, _filename;
int _fd;

};

#endif
