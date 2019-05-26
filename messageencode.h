#ifndef MESSAGEENCODE_H
#define MESSAGEENCODE_H

#include <memory>
#include <string>
#include <map>
#include <utility>
#include <list>
#include <sstream>

#include "huffcodetreenode.h"

class MessageEncode
{
public:
    MessageEncode();
    void build_encoding_map(const std::shared_ptr<HuffCodeTreeNode>&, std::map<char, std::string>&);
    std::string encode(const std::string&);
protected:
    std::map<char, std::string> m_encoding_map;
    void m_set_encoding_map(const std::map<char, std::string>&);
    bool m_encoding_map_set;
};

#endif // MESSAGEENCODE_H
