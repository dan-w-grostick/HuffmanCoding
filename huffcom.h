#ifndef HUFFCOM_H
#define HUFFCOM_H

#include <string>
#include <map>
#include <memory>

#include "huffcodetreenode.h"
#include "calculatefrequency.h"
#include "buildhufftree.h"
#include "messageencode.h"
#include "messagedecode.h"

class HuffCom
{
public:
    HuffCom(const std::string&);
    std::string encode();
    std::string alternate_encode(const std::string&);
    std::string decode(const std::string&);
protected:
    void m_perform_huffman(const std::string&);
    std::map<char, int> m_frequency_map;
    std::shared_ptr<HuffCodeTreeNode> m_root;
    std::string m_source_message;
    std::string m_encoded_message;
    CalculateFrequency m_cal_freq;
    BuildHuffTree m_build_tree;
    MessageEncode m_msg_encode;
    MessageDecode m_msg_decode;
};

#endif // HUFFCOM_H
