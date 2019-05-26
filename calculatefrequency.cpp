#include "calculatefrequency.h"

CalculateFrequency::CalculateFrequency()
{

}

void CalculateFrequency::calculate_frequencies(const std::string &input, std::map<char, int> &frequency_map) {
    if (frequency_map.size() > 0) { frequency_map.clear(); }
    for_each(begin(input), end(input), [&frequency_map](char c) {
        if (frequency_map.find(c) == frequency_map.end()) {
            frequency_map[c] = 1;
        } else {
            ++frequency_map[c];
        }
    });
}
