#include "gtest/gtest.h"
#include "calculatefrequency.h"

const unsigned long ZERO = 0;
const unsigned long ONE = 1;
const unsigned long FOUR = 4;
const unsigned long EIGHTEEN = 18;

TEST(CalculateFrequencyTester, EmptyStringTest) {
    CalculateFrequency service;
    std::map<char, int> map;
    std::string input = "";

    service.calculate_frequencies(input, map);

    ASSERT_TRUE(map.empty());
    ASSERT_EQ(map.size(), ZERO);
}

TEST(CalculateFrequencyTester, RepeatingUniqueCharacterTest) {
    CalculateFrequency service;
    std::map<char, int> map;
    std::string input = "aaaaaaaaaaaa";

    service.calculate_frequencies(input, map);

    ASSERT_FALSE(map.empty());
    ASSERT_EQ(map.size(), ONE);
    ASSERT_EQ(map['a'], 12);
}

TEST(CalculateFrequencyTester, SingleOccurrenceMultiCharacterTest) {
    CalculateFrequency service;
    std::map<char, int> map;
    std::string input = "abcd";

    service.calculate_frequencies(input, map);

    ASSERT_FALSE(map.empty());
    ASSERT_EQ(map.size(), FOUR);
    ASSERT_EQ(map['a'], 1);
    ASSERT_EQ(map['b'], 1);
    ASSERT_EQ(map['c'], 1);
    ASSERT_EQ(map['d'], 1);
}

TEST(CalculateFrequencyTester, RealisticTest) {
    CalculateFrequency service;
    std::map<char, int> map;
    std::string input = "It was the best of times, it was the blurst of times...";

    service.calculate_frequencies(input, map);

    ASSERT_FALSE(map.empty());
    ASSERT_EQ(map.size(), EIGHTEEN);
    ASSERT_EQ(map['I'], 1);
    ASSERT_EQ(map['t'], 8);
    ASSERT_EQ(map[' '], 11);
    ASSERT_EQ(map['w'], 2);
    ASSERT_EQ(map['a'], 2);
    ASSERT_EQ(map['s'], 6);
    ASSERT_EQ(map['h'], 2);
    ASSERT_EQ(map['e'], 5);
    ASSERT_EQ(map['b'], 2);
    ASSERT_EQ(map['o'], 2);
    ASSERT_EQ(map['f'], 2);
    ASSERT_EQ(map['i'], 3);
    ASSERT_EQ(map['m'], 2);
    ASSERT_EQ(map['l'], 1);
    ASSERT_EQ(map['u'], 1);
    ASSERT_EQ(map['r'], 1);
    ASSERT_EQ(map['.'], 3);
    ASSERT_EQ(map[','], 1);
}
