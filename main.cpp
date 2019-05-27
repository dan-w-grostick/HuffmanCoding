#include <iostream>
#include <sstream>

#include "gtest/gtest.h"
#include "huffcom.h"

#define DEBUG_OFF

#ifdef DEBUG_ON
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif
#ifndef DEBUG_ON

void print(const std::string &encode, const std::string &decode) {
    std::stringstream stream;

    stream << "The encoded string is: [" << encode << "]..." << std::endl;
    stream << "The decoded string is: [" << decode << "]" << std::endl;

    std::cout << stream.str() << std::endl;
}

int main() {
    std::cout << "Huffman Coding Runner" << std::endl;

//    HuffCom huff_com("It was the best of times, it was the blurst of times...");
    HuffCom huff_com("That he sensed in himself the troubling presence of his unlived life we can divine from the frequency with which he exhibits characters who cry out for the experiences that their tempraments deny them.");

    std::string encode = huff_com.encode();

    std::string decode = huff_com.decode(encode);

    print(encode, decode);

    return 0;
#endif
}
