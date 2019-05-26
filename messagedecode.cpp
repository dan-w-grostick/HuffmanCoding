#include "messagedecode.h"

MessageDecode::MessageDecode()
{

}

std::string MessageDecode::decode(const std::string &code, const std::shared_ptr<HuffCodeTreeNode> &root) {
    std::string return_value = code;

        std::stringstream ss;
        std::shared_ptr<HuffCodeTreeNode> node = root;

    for (char c : code) {
        if (root->left() == nullptr && root->right() == nullptr) {
            ss << root->character();
        } else {
            if (c == '0') {
                node = node->left();
            } else {
                node = node->right();
            }
            if (node->left() == nullptr && node->right() == nullptr) {
                ss << node->character();
                node = root;
            }
        }
    }

    return_value = ss.str();

    return return_value;
}
