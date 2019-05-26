#include "huffcom.h"

HuffCom::HuffCom(const std::string &source_string)
    : m_root(nullptr), m_source_message(source_string)
{
    m_perform_huffman(source_string);
}

std::string HuffCom::encode() {
    return m_msg_encode.encode(m_source_message);
}

std::string HuffCom::alternate_encode(const std::string &message) {
    return m_msg_encode.encode(message);
}

// We need to destroy in:code to decode.  Either pass by copy or create copy here.
std::string HuffCom::decode(const std::string &code) {
    return m_msg_decode.decode(code, m_root);
}

void HuffCom::m_perform_huffman(const std::string &source) {
    // Calculate frequencies of the characters in the input
    m_cal_freq.calculate_frequencies(source, m_frequency_map);

    // Build Huffman Coding tree
    m_build_tree.create_tree(m_frequency_map, m_root);

    // Build encoding map
    std::map<char, std::string> encoding_map;
    m_msg_encode.build_encoding_map(m_root, encoding_map);

    // -- encode

    // -- decode
}
