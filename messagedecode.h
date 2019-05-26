#ifndef MESSAGEDECODE_H
#define MESSAGEDECODE_H

#include <memory>
#include <string>
#include <map>
#include <sstream>

#include "huffcodetreenode.h"

class MessageDecode
{
public:
    MessageDecode();
    std::string decode(const std::string&, const std::shared_ptr<HuffCodeTreeNode>&);
protected:
};

#endif // MESSAGEDECODE_H
