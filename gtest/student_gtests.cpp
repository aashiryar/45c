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
    EXPECT_TRUE(true);
}

TEST(StringFunction, strcmp) {
    EXPECT_TRUE(true);
}

TEST(StringFunction, strncmp) {
    EXPECT_TRUE(true);
}

TEST(StringFunction, reverse_cpy) {
    EXPECT_TRUE(true);
}

TEST(StringFunction, strchr) {
    EXPECT_TRUE(true);
}

TEST(StringFunction, strstr) {
    EXPECT_TRUE(true);
}
