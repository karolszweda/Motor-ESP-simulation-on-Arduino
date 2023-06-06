#include "analysis.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

Analysis::Analysis()
    :_data( new vector<int>() )
{

}
Analysis::Analysis( string filename )
    : _filename( filename ), _data( new vector<int>() )
{
}

Analysis::Analysis( const Analysis& other )
    : _filename( other._filename ), _data( other._data ) 
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

void Analysis::removeData()
{
    if (_data->empty())
    {
        cout << "No data left to remove" << endl;
    } else {
        _data->clear();
        _data->shrink_to_fit();
    }
}

void Analysis::collectData()
{
    cout << "Collected data set: " << endl;
    try {
        ifstream file(_filename); //input file stream - open to read
        if ( !file  ){
            throw std::runtime_error( "Error opening the file" );
        }

        string line;
        int intValue;

        while( getline( file, line ) )
        {
            intValue = stoi( line );
            if( intValue == 50 || intValue == 100 )
            {
                _data->push_back( intValue );
            }
        }
        
        file.close();
           
    }
    catch( const std::exception& e )
    {
        cerr << e.what() << '\n';
    }
}

void Analysis::showData()
{
    cout << "Collected data: " << endl;
    if (_data->empty())
    {
        cout << "No data to show" << endl;
    } else {
        for( const int& storedLine : *_data )
        {
            cout << storedLine << std::endl;
        }
    }
}

void Analysis::sortData()
{
    sort( _data->begin(), _data->end() );
}

//set1 + set2 = set3 (with all data from set one and two)
Analysis Analysis::operator+(const Analysis& other) const
{
    Analysis combined( other );
    combined._data->insert(combined._data->end(), _data->begin(), _data->end());
    combined._data->insert(combined._data->end(), other._data->begin(), other._data->end());
    return combined;
}
 