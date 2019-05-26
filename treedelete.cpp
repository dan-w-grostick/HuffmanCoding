#include "treedelete.h"

TreeDelete::TreeDelete()
{

}

void TreeDelete::dismantle_tree(std::shared_ptr<HuffCodeTreeNode> &root) const {
    std::list<std::shared_ptr<HuffCodeTreeNode>> node_queue;

    if (root != nullptr) {
        node_queue.push_front(root);
        root = nullptr;
        std::shared_ptr<HuffCodeTreeNode> node;

        while (node_queue.size() > 0) {
            node = node_queue.back();
            node_queue.pop_back();

            if (node->left() != nullptr) {
                node_queue.push_front(node->left());
                node->clear_left();
            }

            if (node->right() != nullptr) {
                node_queue.push_front(node->right());
                node->clear_right();
            }
        }
    }
}
