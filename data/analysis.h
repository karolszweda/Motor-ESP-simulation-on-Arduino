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
    Analysis( std::string );

    double getAverage();

    void showData();

    ~Analysis();
};
#endif
