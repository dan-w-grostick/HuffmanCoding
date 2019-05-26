#ifndef CALCULATEFREQUENCY_H
#define CALCULATEFREQUENCY_H

#include <map>
#include <string>

class CalculateFrequency
{
public:
    CalculateFrequency();
    void calculate_frequencies(const std::string&, std::map<char, int>&);
};

#endif // CALCULATEFREQUENCY_H
