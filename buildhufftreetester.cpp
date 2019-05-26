#include "gtest/gtest.h"

#include "buildhufftree.h"

TEST(BuildHuffTreeTester, NoEntryTest) {
    std::map<char, int> frequency_map;

    std::shared_ptr<HuffCodeTreeNode> root
            = std::make_shared<HuffCodeTreeNode>('a', 1);

    BuildHuffTree build_huff_tree;

    build_huff_tree.create_tree(frequency_map, root);

    ASSERT_EQ(root, nullptr);
}

TEST(BuildHuffTreeTester, SingleEntryTest) {
    std::map<char, int> frequency_map;
    frequency_map['k'] = 27;

    std::shared_ptr<HuffCodeTreeNode> root
            = std::make_shared<HuffCodeTreeNode>('a', 1);

    BuildHuffTree build_huff_tree;

    build_huff_tree.create_tree(frequency_map, root);

    ASSERT_NE(root, nullptr);
    ASSERT_EQ(root->frequency(), 27);
    ASSERT_EQ(root->character(), 'k');
    ASSERT_EQ(root->left(), nullptr);
    ASSERT_EQ(root->right(), nullptr);
}

TEST(BuildHuffTreeTester, TwoEntryTest) {
    std::map<char, int> frequency_map;
    frequency_map['k'] = 27;
    frequency_map['w'] = 6;

    std::shared_ptr<HuffCodeTreeNode> root
            = std::make_shared<HuffCodeTreeNode>('a', 1);

    BuildHuffTree build_huff_tree;

    build_huff_tree.create_tree(frequency_map, root);

    ASSERT_NE(root, nullptr);
    ASSERT_EQ(root->frequency(), 33);
    ASSERT_EQ(root->character(), '*');
    ASSERT_NE(root->left(), nullptr);
    ASSERT_NE(root->right(), nullptr);

    ASSERT_EQ(root->left()->frequency(), 6);
    ASSERT_EQ(root->left()->character(), 'w');
    ASSERT_EQ(root->left()->left(), nullptr);
    ASSERT_EQ(root->left()->right(), nullptr);

    ASSERT_EQ(root->right()->frequency(), 27);
    ASSERT_EQ(root->right()->character(), 'k');
    ASSERT_EQ(root->left()->frequency(), 6);
    ASSERT_EQ(root->left()->character(), 'w');
    ASSERT_EQ(root->right()->left(), nullptr);
    ASSERT_EQ(root->right()->right(), nullptr);
}
