#include "gtest/gtest.h"

#include "nodecreate.h"

const unsigned long ZERO = 0;
const unsigned long ONE = 1;
const unsigned long FOUR = 4;
const unsigned long FIVE = 5;

TEST(NodeCreateTester, CreateSimpleNodeTest) {
    NodeCreate node_create;
    std::shared_ptr<HuffCodeTreeNode> node =
            node_create.create_node('X', 13);

    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->character(), 'X');
    ASSERT_EQ(node->frequency(), 13);
}

TEST(NodeCreateTester, SimpleTreeTest) {
    NodeCreate node_create;
    std::shared_ptr<HuffCodeTreeNode> left =
            node_create.create_node('x', 3);
    std::shared_ptr<HuffCodeTreeNode> right =
            node_create.create_node('y', 5);
    std::shared_ptr<HuffCodeTreeNode> root =
            node_create.create_node('z', 8, left, right);

    ASSERT_NE(root, nullptr);
    ASSERT_NE(root->left(), nullptr);
    ASSERT_NE(root->right(), nullptr);
    ASSERT_EQ(root->left()->character(), 'x');
    ASSERT_EQ(root->right()->frequency(), 5);
}

TEST(NodeCreateTester, ChainTreeTest) {
    NodeCreate node_create;
    std::shared_ptr<HuffCodeTreeNode> right_right_right =
            node_create.create_node('a', 1);
    std::shared_ptr<HuffCodeTreeNode> right_right =
            node_create.create_node('b', 2, nullptr, right_right_right);
    std::shared_ptr<HuffCodeTreeNode> right =
            node_create.create_node('c', 3, nullptr, right_right);
    std::shared_ptr<HuffCodeTreeNode> root =
            node_create.create_node('d', 4, nullptr, right);

    ASSERT_NE(root, nullptr);
    ASSERT_EQ(root->left(), nullptr);
    ASSERT_NE(root->right(), nullptr);
    ASSERT_NE(root->right()->right(), nullptr);
    ASSERT_NE(root->right()->right()->right(), nullptr);
    ASSERT_EQ(root->right()->character(), 'c');
    ASSERT_EQ(root->right()->right()->character(), 'b');
    ASSERT_EQ(root->right()->right()->right()->character(), 'a');
}

TEST(NodeCreateTester, EmptyListTest) {
    std::map<char, int> freq_map;
    std::list<std::shared_ptr<HuffCodeTreeNode>> list;
    list.push_back(nullptr);
    NodeCreate node_create;

    ASSERT_EQ(list.size(), ONE);
    node_create.create_node_list(freq_map, list);
    ASSERT_EQ(list.size(), ZERO);
}

TEST(NodeCreateTester, SingleElementTest) {
    std::map<char, int> freq_map;
    freq_map['g'] = 13;
    std::list<std::shared_ptr<HuffCodeTreeNode>> list;
    list.push_back(nullptr);
    NodeCreate node_create;

    ASSERT_EQ(list.size(), ONE);
    node_create.create_node_list(freq_map, list);
    ASSERT_EQ(list.size(), ONE);

    ASSERT_EQ(list.front()->character(), 'g');
    ASSERT_EQ(list.front()->frequency(), 13);
}

TEST(NodeCreateTester, SortedListTest) {
    std::map<char, int> freq_map;
    freq_map['g'] = 13;
    freq_map['m'] = 27;
    freq_map['b'] = 5;
    freq_map['t'] = 19;
    std::list<std::shared_ptr<HuffCodeTreeNode>> list;
    list.push_back(nullptr);
    NodeCreate node_create;

    ASSERT_EQ(list.size(), ONE);
    node_create.create_node_list(freq_map, list);
    ASSERT_EQ(list.size(), FOUR);

    char chars[4] = {'b', 'g', 't', 'm'};
    int count = 0;
    for(std::shared_ptr<HuffCodeTreeNode> &ptr : list) {
        ASSERT_EQ(ptr->character(), chars[count]);

        ++count;
    }
}

TEST(NodeCreateTester, InsertSingleNodeTest) {
    NodeCreate node_create;
    std::shared_ptr<HuffCodeTreeNode> node =
            node_create.create_node('X', 13);
    std::list<std::shared_ptr<HuffCodeTreeNode>> node_list;

    ASSERT_EQ(node_list.size(), ZERO);
    node_create.insert_node(node, node_list);
    ASSERT_EQ(node_list.size(), ONE);
}

TEST(NodeCreateTester, InsertMultiNodeTest) {
    NodeCreate node_create;
    std::shared_ptr<HuffCodeTreeNode> four =
            node_create.create_node('X', 4);
    std::shared_ptr<HuffCodeTreeNode> ten =
            node_create.create_node('X', 10);
    std::shared_ptr<HuffCodeTreeNode> seven =
            node_create.create_node('X', 7);
    std::shared_ptr<HuffCodeTreeNode> two =
            node_create.create_node('X', 2);
    std::shared_ptr<HuffCodeTreeNode> fifteen =
            node_create.create_node('X', 15);
    std::list<std::shared_ptr<HuffCodeTreeNode>> node_list;

    ASSERT_EQ(node_list.size(), ZERO);
    node_create.insert_node(four, node_list);
    node_create.insert_node(ten, node_list);
    node_create.insert_node(seven, node_list);
    node_create.insert_node(two, node_list);
    node_create.insert_node(fifteen, node_list);
    ASSERT_EQ(node_list.size(), FIVE);

    int freqs[5] = {2, 4, 7, 10, 15};
    int count = 0;
    for (const std::shared_ptr<HuffCodeTreeNode> &node : node_list) {
        ASSERT_EQ(node->frequency(), freqs[count]);

        ++count;
    }
}
