#include "messageencode.h"

MessageEncode::MessageEncode()
    : m_encoding_map_set(false)
{

}

void MessageEncode::build_encoding_map(const std::shared_ptr<HuffCodeTreeNode> &root, std::map<char, std::string> &encoding_map) {
    if (!encoding_map.empty()) { encoding_map.clear(); }

    if (root != nullptr) {
        if (root->left() == nullptr && root->right() == nullptr) {
            encoding_map[root->character()] = "0";
        } else {
            std::list<std::pair<std::shared_ptr<HuffCodeTreeNode>, std::string>> queue;
            queue.push_back(std::make_pair(root, ""));
            std::pair<std::shared_ptr<HuffCodeTreeNode>, std::string> element;
            while (queue.size() > 0) {
                element = queue.front();
                queue.pop_front();

                if (element.first->character() != '*') {
                    // This is a value node - add to map
                    encoding_map[element.first->character()] = element.second;
                } else {

                    // Not a value node - add left and right as appropriate
                    if (element.first->left()) {
                        queue.push_back(std::make_pair(element.first->left(), element.second + "0"));
                    }

                    if (element.first->right()) {
                        queue.push_back(std::make_pair(element.first->right(), element.second + "1"));
                    }
                }
            }
        }
    }

    m_set_encoding_map(encoding_map);
}

std::string MessageEncode::encode(const std::string &source) {
    std::string return_value = source;

    if (m_encoding_map_set) {
        std::stringstream ss;

        for (char c : source) {
            ss << m_encoding_map[c];
        }

        return_value = ss.str();
    }

    return return_value;
}

void MessageEncode::m_set_encoding_map(const std::map<char, std::string> &encoding_map) {
    m_encoding_map = encoding_map;
    m_encoding_map_set = true;
}
