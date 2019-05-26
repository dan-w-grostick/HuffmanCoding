#include "gtest/gtest.h"

#include "treedelete.h"

TEST(TreeDeleteTester, NullTreeTest) {
    std::shared_ptr<HuffCodeTreeNode> root = nullptr;
    TreeDelete tree_delete;

    tree_delete.dismantle_tree(root);

    ASSERT_EQ(root, nullptr);
}

TEST(TreeDeleteTester, ThreeNodeTest) {
    std::shared_ptr<HuffCodeTreeNode> left = std::make_shared<HuffCodeTreeNode>('0', 0);
    std::shared_ptr<HuffCodeTreeNode> right = std::make_shared<HuffCodeTreeNode>('0', 0);
    std::shared_ptr<HuffCodeTreeNode> root = std::make_shared<HuffCodeTreeNode>('a', 1, left, right);

    TreeDelete tree_delete;

    tree_delete.dismantle_tree(root);

    ASSERT_EQ(root, nullptr);
    ASSERT_NE(left, nullptr);
    ASSERT_NE(right, nullptr);
}

TEST(TreeDeleteTester, NodeChainTest) {
    std::shared_ptr<HuffCodeTreeNode> sub = std::make_shared<HuffCodeTreeNode>('0', 1);
    std::shared_ptr<HuffCodeTreeNode> child = std::make_shared<HuffCodeTreeNode>('0', 2, sub);
    std::shared_ptr<HuffCodeTreeNode> parent = std::make_shared<HuffCodeTreeNode>('0', 3, child);
    std::shared_ptr<HuffCodeTreeNode> root = std::make_shared<HuffCodeTreeNode>('a', 4, parent);

    TreeDelete tree_delete;

    ASSERT_NE(root, nullptr);
    ASSERT_NE(parent->left(), nullptr);
    ASSERT_NE(child->left(), nullptr);
    ASSERT_NE(sub, nullptr);

    tree_delete.dismantle_tree(root);

    ASSERT_EQ(root, nullptr);
    ASSERT_EQ(parent->left(), nullptr);
    ASSERT_EQ(child->left(), nullptr);
    ASSERT_EQ(sub->left(), nullptr);
}

TEST(TreeDeleteTester, LeftRightNodeChainTest) {
    std::shared_ptr<HuffCodeTreeNode> sub2 = std::make_shared<HuffCodeTreeNode>('0', 1);
    std::shared_ptr<HuffCodeTreeNode> sub1 = std::make_shared<HuffCodeTreeNode>('0', 2, sub2);
    std::shared_ptr<HuffCodeTreeNode> sub = std::make_shared<HuffCodeTreeNode>('0', 3, nullptr, sub1);
    std::shared_ptr<HuffCodeTreeNode> child = std::make_shared<HuffCodeTreeNode>('0', 4, sub);
    std::shared_ptr<HuffCodeTreeNode> parent = std::make_shared<HuffCodeTreeNode>('0', 5, nullptr, child);
    std::shared_ptr<HuffCodeTreeNode> root = std::make_shared<HuffCodeTreeNode>('a', 6, parent);

    TreeDelete tree_delete;

    ASSERT_NE(root->left(), nullptr);
    ASSERT_NE(parent->right(), nullptr);
    ASSERT_NE(child->left(), nullptr);
    ASSERT_NE(sub->right(), nullptr);
    ASSERT_NE(sub1->left(), nullptr);
    ASSERT_NE(sub2, nullptr);

    tree_delete.dismantle_tree(root);


    ASSERT_EQ(root, nullptr);
    ASSERT_EQ(parent->right(), nullptr);
    ASSERT_EQ(child->left(), nullptr);
    ASSERT_EQ(sub->right(), nullptr);
    ASSERT_EQ(sub1->left(), nullptr);
}
