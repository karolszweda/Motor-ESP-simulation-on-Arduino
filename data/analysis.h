#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <iostream>
#include <string>

class Analysis
{
private:

    int _fd;
    double _average;
    std::string _filename;
    std::vector<int> *_data;

public:
    Analysis();

    Analysis( const std::string );

    Analysis( const Analysis& other );

    double getAverage();

    void removeData();

    void collectData();

    void showData();

    void sortData();

    bool operator==( const Analysis& other ) const;

    ~Analysis();
};
#endif
