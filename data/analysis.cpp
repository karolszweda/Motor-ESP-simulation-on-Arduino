#include <iostream>
#include <fstream>
#include <string>

int main()
{
    try {

        std::ifstream data("data.txt"); //input file stream - open to read
        if ( !data  ){
            throw std::runtime_error( "Error opening the file" );
        }

        std::string line;
        while( std::getline( data, line ) )
        {
            std::cout << line << std::endl;
            

        }
        
        data.close();
           
    }
    catch( const std::exception& e )
    {
        std::cerr << e.what() << '\n';
        
    }
    
    
}