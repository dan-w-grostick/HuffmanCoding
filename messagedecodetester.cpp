#include "gtest/gtest.h"

#include "messagedecode.h"

TEST(MessageDecodeTester, SingleNodeTest) {
    MessageDecode message_decode;

    std::shared_ptr<HuffCodeTreeNode> root =
            std::make_shared<HuffCodeTreeNode>('z', 49);

    std::string message = message_decode.decode("0000000", root);

    ASSERT_STRCASEEQ(message.c_str(), "zzzzzzz");
}

TEST(MessageDecodeTester, SimpleTreeTest) {
    MessageDecode message_decode;

    std::shared_ptr<HuffCodeTreeNode> left =
            std::make_shared<HuffCodeTreeNode>('r', 32);
    std::shared_ptr<HuffCodeTreeNode> right =
            std::make_shared<HuffCodeTreeNode>('s', 17);

    std::shared_ptr<HuffCodeTreeNode> root =
            std::make_shared<HuffCodeTreeNode>('*', 49, left, right);

    std::string message = message_decode.decode("1100101101", root);

    ASSERT_STRCASEEQ(message.c_str(), "ssrrsrssrs");
}
