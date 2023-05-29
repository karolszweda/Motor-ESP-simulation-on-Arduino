#include <iostream>
#include "serialport.h"

using namespace std;


int main()
{   

    int choice = -1;
    Serialport Arduino( "/dev/cu.usbmodem1401", "data.txt" );

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
            cout << "Serial port:" << endl;
            Arduino.connect();
            Arduino.readSerial(5);
            Arduino.disconnect();
            break;
        case 2:
            cout << "Data" << endl;

            //uzyj konstruktora kopiujacego do zachowania tego samego portu ale nowe dane chyba
            break;
        case 3:
            cout << "Average" << endl;
             // set floating-point output formatting
            // cout << fixed << setprecision( 2 );
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
