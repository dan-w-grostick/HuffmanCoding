#include "nodecreate.h"

NodeCreate::NodeCreate()
{

}

void NodeCreate::create_node_list(const std::map<char, int> &frequency_map, std::list<std::shared_ptr<HuffCodeTreeNode>> &node_list) const {
    if (node_list.size() > 0) { node_list.clear(); }

    for_each(begin(frequency_map), end(frequency_map), [&node_list](const std::pair<char, int> key_val) {
        node_list.push_back(std::make_shared<HuffCodeTreeNode>(key_val.first, key_val.second));
    });

    node_list.sort([](const std::shared_ptr<HuffCodeTreeNode> &a, const std::shared_ptr<HuffCodeTreeNode> &b) {
        return a->frequency() < b->frequency();
    });
}

std::shared_ptr<HuffCodeTreeNode> NodeCreate::create_node(char c, int i, std::shared_ptr<HuffCodeTreeNode> left, std::shared_ptr<HuffCodeTreeNode> right) const {
    return std::make_shared<HuffCodeTreeNode>(c, i, left, right);
}


void NodeCreate::insert_node(const std::shared_ptr<HuffCodeTreeNode> &node, std::list<std::shared_ptr<HuffCodeTreeNode>> &node_list) const {
    if (node_list.size() == 0) {
        node_list.push_back(node);
    } else {
        bool inserted = false;
        for (std::list<std::shared_ptr<HuffCodeTreeNode>>::iterator iter = begin(node_list); iter != end(node_list); ++iter) {
            if (node->frequency() < (*iter)->frequency()){
                node_list.insert(iter, node);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            node_list.push_back(node);
        }
    }
}
