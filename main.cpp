#include <iostream>
#include <sstream>
#include <memory>

#include "gtest/gtest.h"
#include "huffcom.h"
#include "huffcomstring.h"

#define TESTING_OFF

#ifdef TESTING_ON
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif
#ifndef TESTING_ON

void print(const std::vector<bool> &encoded_bits, const std::string &decode) {
    std::stringstream stream;

    stream << "The encoded string is: [";
    for_each(begin(encoded_bits), end(encoded_bits), [&stream](const bool &bit) { stream << bit; });
    stream << "]" << std::endl;
    stream << "The encoded size is " << sizeof (encoded_bits) << std::endl;
    stream << "The decoded string is: [" << decode << "]" << std::endl;
    stream << "The decoded size is " << sizeof (decode) << std::endl;

    std::cout << stream.str() << std::endl;
}

void print(const std::string &encode, const std::string &decode) {
    std::stringstream stream;

    stream << "The encoded string is: [" << encode << "]..." << std::endl;
    stream << "The encoded size is " << sizeof (encode) << std::endl;
    stream << "The decoded string is: [" << decode << "]" << std::endl;
    stream << "The decoded size is " << sizeof (decode) << std::endl;

    std::cout << stream.str() << std::endl;
}

int main() {
//    bool use_bits = true;
    std::cout << "Huffman Coding Runner" << std::endl;

//    HuffCom huff_com("It was the best of times, it was the blurst of times...");
//    HuffCom huff_com("That he sensed in himself the troubling presence of his unlived life we can divine from the frequency with which he exhibits characters who cry out for the experiences that their tempraments deny them.");
    std::unique_ptr<HuffCom> huff_com =
            std::make_unique<HuffComString>("That he sensed in himself the troubling presence of his unlived life we can divine from the frequency with which he exhibits characters who cry out for the experiences that their tempraments deny them.");

//    if (use_bits) {
//        std::vector<bool> encoded_bits;
//        huff_com->encode_bits(encoded_bits);

//        std::string decode = "beep"; //huff_com.decode_bits(encoded_bits);

//        print(encoded_bits, decode);
//    } else {
        std::string encode = huff_com->encode();

        std::string decode = huff_com->decode(encode);

        print(encode, decode);
//    }

    return 0;
#endif
}
