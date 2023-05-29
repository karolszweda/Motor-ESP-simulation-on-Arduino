#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
    try {

        std::ifstream data("data.txt"); //input file stream - open to read
        if ( !data  ){
            throw std::runtime_error( "Error opening the file" );
        }

        std::string line;
        std::vector<std::string> lines;
        
        
        while( std::getline( data, line ) )
        {
            lines.push_back( line );
        }
        
        data.close();

        for(const std::string& storedLine : lines)
        {
            std::cout << storedLine << std::endl;
        }
           
    }
    catch( const std::exception& e )
    {
        std::cerr << e.what() << '\n';
        
    }
    
    
}