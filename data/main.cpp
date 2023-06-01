#include <iostream>
#include "serialport.h"
#include "analysis.h"

using namespace std;


int main()
{   
    Serialport Arduino( "/dev/cu.usbmodem1401", "data.txt" );
    Analysis Set1("data.txt");

    int choice = -1;
    unsigned int time = 10;

    while ( choice != 0 )
    {
        cout << "Possible options:" << endl;
        cout << "1 - show serial port stream" << endl;
        cout << "2 - show data" << endl;
        cout << "3 - calculate the average" << endl;
        cout << "0 - close" << endl;
        cout << "Enter your choice: "; cin >> choice;

        switch ( choice )
        {
        case 0:
            cout << "Exitting" << endl;
            exit( EXIT_SUCCESS );
        case 1:
            cout << "Enter time (seconds): "; cin >> time;
            cout << "Serial port:" << endl;

            Arduino.connect();
            Arduino.readSerial( time );
            Arduino.disconnect();

            break;
        case 2:
            Set1.showData();
            break;
        case 3:
            Set1.getAverage();
            break;
        default:
            cout << "Incorrect choice!" << endl;
            break;
        }
        
        if ( choice != 0)
        {
            cout << "Press Enter to continue ";
            cin.ignore();
            cin.get();
        }
    }
    
    return 0;
}
