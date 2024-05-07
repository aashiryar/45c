#include <gtest/gtest.h>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;

    EXPECT_EQ(foo_list->data, 'f');
    // ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);

    list::free(foo_list_head);
}

TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);
}

// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.

TEST(ListTests, ReplaceMe) {
    EXPECT_TRUE(true);
}
TEST(ListTests, FromString) {
    const char* s = "hello";
    list::Node* head = list::from_string(s);
    std::string result;
    for (list::Node* current = head; current != nullptr; current = current->next) {
        result += current->data;
    }
    EXPECT_EQ(result, s);
    list::free(head);
}

TEST(ListTests, Free) {
    list::Node* head = new list::Node{'h', new list::Node{'e', new list::Node{'l', new list::Node{'l', new list::Node{'o', nullptr}}}}};
    list::free(head);
    EXPECT_EQ(head, nullptr);
}

TEST(ListTests, Print) {
    list::Node* head = new list::Node{'h', new list::Node{'e', new list::Node{'l', new list::Node{'l', new list::Node{'o', nullptr}}}}};
    std::stringstream ss;
    std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
    list::print(std::cout, head);
    EXPECT_EQ(ss.str(), "hello");
    list::free(head);
}
