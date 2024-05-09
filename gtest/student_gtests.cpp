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
    Node* const head2 = list::from_string("");
    EXPECT_EQ(list::length(head2), 0);
    list::free(head2);
}

// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.

TEST(ListTests, ReplaceMe) {
    EXPECT_TRUE(true);
}
TEST(ListTests, FromString) {
    const char* s = "hello";
    list::Node* head = list::from_string(s);
    EXPECT_EQ(head->data, 'h');
    EXPECT_EQ(head->next->data, 'e');
    EXPECT_EQ(head->next->next->data, 'l');
    EXPECT_EQ(head->next->next->next->data, 'l');
    EXPECT_EQ(head->next->next->next->next->data, 'o');
    EXPECT_EQ(head->next->next->next->next->next, nullptr);
    list::free(head);
}

TEST(ListTests, Free) {
    list::Node* head = new list::Node{'h', new list::Node{'e', new list::Node{'l', new list::Node{'l', new list::Node{'o', nullptr}}}}};
    list::free(head);
    ASSERT_NE(head, (nullptr));
}

TEST(ListTests, Print) {
    list::Node* head = new list::Node{'h', new list::Node{'e', new list::Node{'l', new list::Node{'l', new list::Node{'o', nullptr}}}}};
    std::stringstream ss;
    list::print(std::cout, head);
    EXPECT_EQ(ss.str(), "");
    list::free(head);
}
TEST(ListTests, Nth) {
    Node* const foo_list_head = list::from_string("foo");
    Node* nth = list::nth(foo_list_head, 1);
    EXPECT_EQ(nth->data, 'o');
    list::free(foo_list_head);
}
/*TEST(ListTests, NthEmptyList) {
    list::Node* head = nullptr; // Empty list
    list::Node* nth_node = list::nth(head, 2);
    EXPECT_EQ(nth_node, nullptr);
}*/
TEST(ListTests, Last) {
    Node* const foo_list_head = list::from_string("foo");
    Node* last = list::last(foo_list_head);
    EXPECT_EQ(last->data, 'o');
    EXPECT_EQ(last->next, nullptr);
    list::free(foo_list_head);
}

TEST(ListTests, Reverse) {
    Node* original  = list::from_string("abc");
    Node* reversed = list::reverse(original);
    EXPECT_EQ(reversed->data,'c');
    EXPECT_EQ(reversed->next->data,'b');
    EXPECT_EQ(reversed->next->next->data,'a');
    EXPECT_EQ(reversed->next->next->next, nullptr);
    list::free(original);
    list::free(reversed);
    Node* const q1 = list::from_string("");
    Node* const q2 = list::reverse(q1);
    EXPECT_TRUE(q2==nullptr);
    list::free(q1);
    list::free(q2);
}
TEST(ListTests, FindList) {
    Node* hay  = list::from_string("abcd");
    Node* needle = list::from_string("bc");
    Node* found = list::find_list(hay,needle);
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->data, 'b');
    list::free(hay);
    list::free(needle);
}
TEST(ListTests, FindChar) {
    Node* hay  = list::from_string("abcd");
    Node* found = list::find_char(hay,'c');
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->data, 'c');
    //Node* not_found = list::find_char(hay,'d');
    //EXPECT_EQ(not_found, nullptr);
    list::free(hay);
}
TEST(ListTests, Append) {
    list::Node* lhs = list::from_string("123");
    list::Node* rhs = list::from_string("45");
    list::Node* result = list::append(lhs, rhs);
    EXPECT_EQ(result->data, '1');
    EXPECT_EQ(result->next->data, '2');
    EXPECT_EQ(result->next->next->data, '3');
    EXPECT_EQ(result->next->next->next->data, '4');
    EXPECT_EQ(result->next->next->next->next->data, '5');
    EXPECT_EQ(result->next->next->next->next->next, nullptr);
    list::free(result);
    list::free(lhs);
    list::free(rhs);
}
TEST(ListTests, IndexExistingNode) {
    list::Node* head = list::from_string("123");
    list::Node* nodeToFind = head->next->next;
    int result = list::index(head, nodeToFind);
    EXPECT_EQ(result, 2);
    list::free(head);
}

TEST(ListTests, CompareLists) {
    list::Node* lhs = list::from_string("123");
    list::Node* rhs = list::from_string("123");
    int result = list::compare(lhs, rhs);
    EXPECT_EQ(result, 0);
    list::free(lhs);
    list::free(rhs);
    Node* const lhs1 = list::from_string("");
    Node* const rhs1 = list::from_string("foo");
    int result1 = list::compare(lhs1, rhs1);
    EXPECT_EQ(result1, -1);
    list::free(lhs1);
    list::free(rhs1);
    Node* const lhs2 = list::from_string("foo");
    Node* const rhs2 = list::from_string("fooboo");
    int result2 = list::compare(lhs2, rhs2);
    EXPECT_EQ(result2, -1);
    list::free(lhs2);
    list::free(rhs2);
}
TEST(ListTests, CompareNElements) {
    list::Node* lhs = list::from_string("123");;
    list::Node* rhs = list::from_string("123");;
    int result = list::compare(lhs, rhs, 3);
    EXPECT_EQ(result, 0);
    list::free(lhs);
    list::free(rhs);
    Node* const lhs3 = list::from_string("abc");
    Node* const rhs3 = list::from_string("abcdef");
    int result3 = list::compare(lhs3, rhs3,5);
    EXPECT_EQ(result3, -1);
    list::free(lhs3);
    list::free(rhs3);
}