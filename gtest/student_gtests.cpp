#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
    char result[10];
	EXPECT_EQ(String::strncpy(result, "foo", 2), result);
	EXPECT_STREQ(result, "fo");
	EXPECT_EQ(String::strncpy(result, "foo", 0), result);
	EXPECT_STREQ(result, "");
	EXPECT_EQ(String::strncpy(result, "", 2), result);
	EXPECT_STREQ(result, "");
}

TEST(StringFunction, strcat) {
	char dest[10] = "bye";
	EXPECT_EQ(String::strcat(dest, "hello"), dest);
	EXPECT_STREQ(dest, "byehello");
	EXPECT_EQ(String::strcat(dest, ""), dest);
	EXPECT_STREQ(dest, "byehello");

	char dest2[10] = "";
	EXPECT_EQ(String::strcat(dest2, "hello"), dest2);
	EXPECT_STREQ(dest2, "hello");
	char dest3[10] = "";
	EXPECT_EQ(String::strcat(dest3, ""), dest3);
	EXPECT_STREQ(dest3, "");
}

TEST(StringFunction, strncat) {
    char dest[10] = "bye";
	EXPECT_EQ(String::strncat(dest, "hello", 2), dest);
	EXPECT_STREQ(dest, "byehe");
	EXPECT_EQ(String::strncat(dest, "hello",0), dest);
	EXPECT_STREQ(dest, "byehe");
	char dest2[10] = "";
	EXPECT_EQ(String::strncat(dest2, "hello", 5), dest2);
	EXPECT_STREQ(dest2, "hello");
	//EXPECT_EQ(String::strncat(dest2, "hello", 8), dest2);
	//EXPECT_STREQ(dest2, "hellohello");
	char dest3[10] = "";
	EXPECT_EQ(String::strncat(dest3, "",2), dest3);
	EXPECT_STREQ(dest3, "");
}

TEST(StringFunction, strcmp) {
    char left[] = "";
	char right[] = "";
	EXPECT_EQ(String::strcmp(left, right), 0);
	char left1[] = "hello";
	char right1[] = "hello";
	EXPECT_EQ(String::strcmp(left1, right1), 0);
	char left2[] = "hellb";
	char right2[] = "hello";
	EXPECT_EQ(String::strcmp(left2, right2), -13);
	char left3[] = "hello";
	char right3[] = "bye";
	EXPECT_EQ(String::strcmp(left3, right3), 6);
	char left4[] = "abc";
	char right4[] = "ab";
	EXPECT_EQ(String::strcmp(left4, right4), 99);
	char left5[] = "abd";
	char right5[] = "abc";
	EXPECT_EQ(String::strcmp(left5, right5), 1);
}

TEST(StringFunction, strncmp) {
	char left[] = "";
	char right[] = "";
	EXPECT_EQ(String::strncmp(left, right, 3), 0);
	char left1[] = "hello";
	char right1[] = "hellb";
	EXPECT_EQ(String::strncmp(left1, right1, 4), 0);
	char left2[] = "hellb";
	char right2[] = "hello";
	EXPECT_EQ(String::strncmp(left2, right2, 5), -13);
	char left3[] = "hello";
	char right3[] = "bye";
	EXPECT_EQ(String::strncmp(left3, right3, 8), 6);
	char left4[] = "abc";
	char right4[] = "ab";
	EXPECT_EQ(String::strncmp(left4, right4, 0), 0);
}

TEST(StringFunction, reverse_cpy) {
	char result[10];
	String::reverse_cpy(result, "hello");
	EXPECT_STREQ(result, "olleh");
	String::reverse_cpy(result, "");
	EXPECT_STREQ(result, "");
	String::reverse_cpy(result, "a");
	EXPECT_STREQ(result, "a");
	char result1[10] = "hello";
	String::reverse_cpy(result1, "bye");
	EXPECT_STREQ(result1, "eyb");
}

TEST(StringFunction, strchr) {
    EXPECT_TRUE(true);
}

TEST(StringFunction, strstr) {
    EXPECT_TRUE(true);
}
