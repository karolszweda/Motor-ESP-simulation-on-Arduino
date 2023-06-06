#include <iostream>
#include "serialport.h"
#include "analysis.h"

using namespace std;


int main()
{   
    Serialport Arduino( "/dev/cu.usbmodem1401", "data.txt" );

    Analysis Set1("data.txt");

    Analysis Set1Copy( Set1 );

    Analysis Set1Copy2( Set1Copy );

    int choice = -1;
    unsigned int time = 10;

    while ( choice != 0 )
    {
        cout << "\nPossible options:" << endl;
        cout << "1 - show serial port stream" << endl;
        cout << "2 - show data" << endl;
        cout << "3 - calculate the average" << endl;
        cout << "4 - remove data" << endl;
        cout << "5 - Copy and sort" << endl;
        cout << "6 - Add to data sets "<< endl;
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
            Set1.collectData();
            Set1.showData();
            break;
        case 3:
            Set1.getAverage();
            break;
        case 4:
            Set1.removeData();
            break;
        case 5:
            Set1Copy.sortData();
            Set1Copy.showData();
            Set1Copy.removeData();
            break;
        case 6:
            if( Set1Copy2 == Set1Copy ) {
                cout << "The sets are ideantical" << endl;
            } else {
                cout << "The sets are not ideantical" << endl;
            }
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

