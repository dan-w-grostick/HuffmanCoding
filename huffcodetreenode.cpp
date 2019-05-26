#include "huffcodetreenode.h"

HuffCodeTreeNode::HuffCodeTreeNode(char character, int frequency,
            std::shared_ptr<HuffCodeTreeNode> left,
            std::shared_ptr<HuffCodeTreeNode> right)
    : m_character(character), m_frequency(frequency), m_left_ptr(left), m_right_ptr(right)
{

}

std::shared_ptr<HuffCodeTreeNode> HuffCodeTreeNode::left() {
    return m_left_ptr;
}

std::shared_ptr<HuffCodeTreeNode> HuffCodeTreeNode::right() {
    return m_right_ptr;
}

void HuffCodeTreeNode::clear_left() {
    m_left_ptr = nullptr;
}

void HuffCodeTreeNode::clear_right() {
    m_right_ptr = nullptr;
}

char HuffCodeTreeNode::character() { return m_character; }

int HuffCodeTreeNode::frequency() { return m_frequency; }
