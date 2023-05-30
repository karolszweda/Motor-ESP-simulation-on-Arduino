#include "analysis.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Analysis::Analysis( string filename )
    : _filename( filename ), _data( new vector<int>() )
{
}

Analysis::~Analysis()
{
    delete _data;
}

double Analysis::getAverage()
{   
    if (_data->empty())
    {
        cout << "No data provided!" << endl;
    }

    int sum = 0;
    for (int line: *_data )
    {
        sum += line;
    } 
    _average = static_cast<double>( sum ) / _data->size();
    cout << "The average is: " << _average << endl;
    return _average;
}

void Analysis::showData()
{
    try {
        ifstream file(_filename); //input file stream - open to read
        if ( !file  ){
            throw std::runtime_error( "Error opening the file" );
        }

        string line;
        int intValue;

        while( getline( file, line ) )
        {

            // if ( line == "100" || line == "050")
            // {
                //cast string into int
                intValue = stoi( line );
                _data->push_back( intValue );
            // }
            // else
            // {
            //     throw std::runtime_error("Error converting to integer");
            // }
 
        }
        
        file.close();

        for(const int& storedLine : *_data)
        {
            cout << storedLine << std::endl;
        }
           
    }
    catch( const std::exception& e )
    {
        cerr << e.what() << '\n';
        
    }
}
