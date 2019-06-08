#ifndef HUFFCOMSTRING_H
#define HUFFCOMSTRING_H


#include <string>
#include <memory>

#include "huffcom.h"
#include "huffcodetreenode.h"
#include "calculatefrequency.h"
#include "buildhufftree.h"
#include "messageencode.h"
#include "messagedecode.h"

class HuffComString : public HuffCom
{
public:
    HuffComString(const std::string&);
//    ~HuffComString();
    std::string encode();
    std::string alternate_encode(const std::string&);
    std::string decode(const std::string&);
protected:
//    void m_perform_huffman(const std::string&);
//    std::map<char, int> m_frequency_map;
//    std::shared_ptr<HuffCodeTreeNode> m_root;
//    std::string m_source_message;
//    std::string m_encoded_message;
//    CalculateFrequency m_cal_freq;
//    BuildHuffTree m_build_tree;
//    MessageEncode m_msg_encode;
//    MessageDecode m_msg_decode;
};

#endif // HUFFCOMSTRING_H
