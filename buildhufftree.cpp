#include "buildhufftree.h"

BuildHuffTree::BuildHuffTree()
{

}

void BuildHuffTree::create_tree(std::map<char, int> &frequency_map,
                                std::shared_ptr<HuffCodeTreeNode> &root) const {
    if (root != nullptr) { m_tree_delete.dismantle_tree(root); }

    std::list<std::shared_ptr<HuffCodeTreeNode>> node_list;
    m_node_create.create_node_list(frequency_map, node_list);

    std::shared_ptr<HuffCodeTreeNode> left;
    std::shared_ptr<HuffCodeTreeNode> right;
    while (node_list.size() > 1) {
        left = node_list.front();
        node_list.pop_front();
        right = node_list.front();
        node_list.pop_front();

        m_node_create.insert_node(
                    m_node_create.create_node(
                        '*',
                        left->frequency() + right->frequency(),
                        left,
                        right), node_list);
    }

    if (node_list.empty())
        root = nullptr;
    else
        root = node_list.front();
}
