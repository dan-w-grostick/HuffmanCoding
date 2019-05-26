#ifndef BUILDHUFFTREE_H
#define BUILDHUFFTREE_H

#include <memory>
#include <list>
#include <map>

#include "huffcodetreenode.h"
#include "treedelete.h"
#include "nodecreate.h"

class BuildHuffTree
{
public:
    BuildHuffTree();
    void create_tree(std::map<char, int>&, std::shared_ptr<HuffCodeTreeNode>&) const;
protected:
    TreeDelete m_tree_delete;
    NodeCreate m_node_create;
};

#endif // BUILDHUFFTREE_H
