#ifndef NODECREATE_H
#define NODECREATE_H

#include <memory>
#include <list>
#include <map>
#include <utility>
#include <algorithm>

#include "huffcodetreenode.h"

class NodeCreate
{
public:
    NodeCreate();
    void create_node_list(const std::map<char, int>&, std::list<std::shared_ptr<HuffCodeTreeNode>>&) const;
    std::shared_ptr<HuffCodeTreeNode> create_node(char, int, std::shared_ptr<HuffCodeTreeNode> left = nullptr, std::shared_ptr<HuffCodeTreeNode> right = nullptr) const;
    void insert_node(const std::shared_ptr<HuffCodeTreeNode>&, std::list<std::shared_ptr<HuffCodeTreeNode>>&) const;
};

#endif // NODECREATE_H
