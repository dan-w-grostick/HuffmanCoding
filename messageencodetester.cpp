#include "gtest/gtest.h"

#include "messageencode.h"

TEST(MessageEncodeTester, EmptyTreeTest) {
    std::map<char, std::string> encoding_map;
    encoding_map['i'] = "0";

    std::shared_ptr<HuffCodeTreeNode> root = nullptr;
//            std::make_shared<HuffCodeTreeNode>('b', 42);

    MessageEncode message_encode;

    ASSERT_FALSE(encoding_map.empty());

    message_encode.build_encoding_map(root, encoding_map);

    ASSERT_TRUE(encoding_map.empty());
}

TEST(MessageEncodeTester, SingleElementTest) {
    std::map<char, std::string> encoding_map;
    encoding_map['i'] = "0";

    std::shared_ptr<HuffCodeTreeNode> root =
            std::make_shared<HuffCodeTreeNode>('b', 42);

    MessageEncode message_encode;

    ASSERT_FALSE(encoding_map.empty());

    message_encode.build_encoding_map(root, encoding_map);

    ASSERT_FALSE(encoding_map.empty());
    ASSERT_STRCASEEQ(encoding_map['b'].c_str(), "0");
}

TEST(MessageEncodeTester, TwoElementTest) {
    std::map<char, std::string> encoding_map;
    encoding_map['i'] = "0";

    std::shared_ptr<HuffCodeTreeNode> left =
            std::make_shared<HuffCodeTreeNode>('x', 17);
    std::shared_ptr<HuffCodeTreeNode> right =
            std::make_shared<HuffCodeTreeNode>('y', 13);

    std::shared_ptr<HuffCodeTreeNode> root =
            std::make_shared<HuffCodeTreeNode>('*', 30, left, right);

    MessageEncode message_encode;

    ASSERT_FALSE(encoding_map.empty());

    message_encode.build_encoding_map(root, encoding_map);

    ASSERT_FALSE(encoding_map.empty());
    ASSERT_STRCASEEQ(encoding_map['x'].c_str(), "0");
    ASSERT_STRCASEEQ(encoding_map['y'].c_str(), "1");
}

TEST(MessageEncodeTester, ElementChainTest) {
    std::map<char, std::string> encoding_map;
    encoding_map['i'] = "0";

    std::shared_ptr<HuffCodeTreeNode> left =
            std::make_shared<HuffCodeTreeNode>('x', 17);
    std::shared_ptr<HuffCodeTreeNode> right =
            std::make_shared<HuffCodeTreeNode>('y', 13);

    std::shared_ptr<HuffCodeTreeNode> child =
            std::make_shared<HuffCodeTreeNode>('*', 30, left, right);

    std::shared_ptr<HuffCodeTreeNode> parent =
            std::make_shared<HuffCodeTreeNode>('*', 30, child);

    std::shared_ptr<HuffCodeTreeNode> root =
            std::make_shared<HuffCodeTreeNode>('*', 30, nullptr, parent);

    MessageEncode message_encode;

    ASSERT_FALSE(encoding_map.empty());

    message_encode.build_encoding_map(root, encoding_map);

    ASSERT_FALSE(encoding_map.empty());
    ASSERT_STRCASEEQ(encoding_map['x'].c_str(), "100");
    ASSERT_STRCASEEQ(encoding_map['y'].c_str(), "101");
}

TEST(MessageEncodeTester, UnitializedEncodeTest) {

    MessageEncode message_encode;


    std::string code = message_encode.encode("xy");

    ASSERT_STRCASEEQ(code.c_str(), "xy");
}

TEST(MessageEncodeTester, TwoCharacterEncodeTest) {
    std::map<char, std::string> encoding_map;
    encoding_map['i'] = "0";

    std::shared_ptr<HuffCodeTreeNode> left =
            std::make_shared<HuffCodeTreeNode>('x', 17);
    std::shared_ptr<HuffCodeTreeNode> right =
            std::make_shared<HuffCodeTreeNode>('y', 13);

    std::shared_ptr<HuffCodeTreeNode> root =
            std::make_shared<HuffCodeTreeNode>('*', 30, left, right);

    MessageEncode message_encode;

    message_encode.build_encoding_map(root, encoding_map);

    std::string code = message_encode.encode("xy");

    ASSERT_STRCASEEQ(code.c_str(), "01");
}

TEST(MessageEncodeTester, ElementChainEncodeTest) {
    std::map<char, std::string> encoding_map;
    encoding_map['i'] = "0";

    std::shared_ptr<HuffCodeTreeNode> left =
            std::make_shared<HuffCodeTreeNode>('x', 17);
    std::shared_ptr<HuffCodeTreeNode> right =
            std::make_shared<HuffCodeTreeNode>('y', 13);

    std::shared_ptr<HuffCodeTreeNode> child =
            std::make_shared<HuffCodeTreeNode>('*', 30, left, right);

    std::shared_ptr<HuffCodeTreeNode> parent =
            std::make_shared<HuffCodeTreeNode>('*', 30, child);

    std::shared_ptr<HuffCodeTreeNode> root =
            std::make_shared<HuffCodeTreeNode>('*', 30, nullptr, parent);

    MessageEncode message_encode;

    message_encode.build_encoding_map(root, encoding_map);

    std::string code = message_encode.encode("xxyyxyxy");

    ASSERT_STRCASEEQ(code.c_str(), "100100101101100101100101");
}
