#ifndef TREEDELETE_H
#define TREEDELETE_H

#include <memory>
#include <list>

#include "huffcodetreenode.h"

class TreeDelete
{
public:
    TreeDelete();
    void dismantle_tree(std::shared_ptr<HuffCodeTreeNode>&) const;
};

#endif // TREEDELETE_H
