#ifndef HUFFCODETREENODE_H
#define HUFFCODETREENODE_H

#include <memory>

class HuffCodeTreeNode;
typedef std::shared_ptr<HuffCodeTreeNode> node; //lazy

class HuffCodeTreeNode
{
public:
    HuffCodeTreeNode(char,
                     int,
                     node left = nullptr,
                     node right = nullptr);
    std::shared_ptr<HuffCodeTreeNode> left();
    std::shared_ptr<HuffCodeTreeNode> right();
    void clear_left();
    void clear_right();
    char character();
    int frequency();
protected:
    char m_character;
    int m_frequency;
    std::shared_ptr<HuffCodeTreeNode> m_left_ptr;
    std::shared_ptr<HuffCodeTreeNode> m_right_ptr;
};

#endif // HUFFCODETREENODE_H
