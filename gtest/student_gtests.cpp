#include <gtest/gtest.h>
#include <string.h>

#include <algorithm>

#include "string.hpp"
#include "alloc.hpp"

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

TEST(StringFunction, strdup) {
    const char* src1 = "Hello, world!";
    char* copied1 = String::strdup(src1);
    EXPECT_STREQ(copied1, src1);
    delete[] copied1;
    const char* src2 = nullptr;
    char* copied2 = String::strdup(src2);
    EXPECT_EQ(copied2, nullptr);
    const char* src3 = "";
    char* copied3 = String::strdup(src3);
    EXPECT_STREQ(copied3, src3);
    delete[] copied3;
    const char* src4 = "!@#$%^&*()_+";
    char* copied4 = String::strdup(src4);
    EXPECT_STREQ(copied4, src4);
    delete[] copied4;
    const char* src5 = "Embedded\0Null\0Characters";
    char* copied5 = String::strdup(src5);
    EXPECT_STREQ(copied5, "Embedded");
    delete[] copied5;
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
	char left5[] = "hello";
	char right5[] = "hello";
	EXPECT_EQ(String::strncmp(left5, right5, 5), 0);
	char left6[] = "hellobc";
	char right6[] = "hellojd";
	EXPECT_EQ(String::strncmp(left6, right6, 5), 0);
	char left7[] = "hello";
	char right7[] = "hello";
	EXPECT_EQ(String::strncmp(left7, right7, 10), 0);
	char left8[] = "byebyhithere";
	char right8[] = "askfjhithere";
	EXPECT_EQ(String::strncmp(left8, right8, 5), 1);
    EXPECT_EQ(String::strncmp("foo", "foo", 3), 0);
    EXPECT_GT(String::strncmp("foo", "bar", 3), 0);
    EXPECT_LT(String::strncmp("bar", "foo", 3), 0);
    EXPECT_EQ(String::strncmp("foobar", "foo", 3), 0);
    EXPECT_NE(String::strncmp("foobar", "foo", 6), 0);
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
    const char str[] = "This is a sample string";
	const char* pch = strchr(str,'s');
	const char dest[] = "s is a sample string";
	EXPECT_STREQ(pch, dest);
	const char str1[] = "abc";
	const char* pch1 = strchr(str1,'b');
	const char dest1[] = "bc";
	EXPECT_STREQ(pch1, dest1);
	const char str2[] = "a";
	const char* pch2 = strchr(str2,'a');
	const char dest2[] = "a";
	EXPECT_STREQ(pch2, dest2);
	const char str3[] = "";
	const char* pch3 = strchr(str3,'a');
	//const char dest3[] = nullptr;
	EXPECT_STREQ(pch3, NULL);
	const char str4[] = "";
	const char* pch4 = strchr(str4,'\0');
	const char dest4[] = "";
	EXPECT_STREQ(pch4, dest4);
	const char str5[] = "Hello There";
	const char* pch5 = strchr(str5,'t');
	EXPECT_STREQ(pch5, NULL);
	const char str6[] = "Hello There";
	const char* pch6 = strchr(str6,' ');
	const char dest6[] = " There";
	EXPECT_STREQ(pch6, dest6);
	const char str7[] = "This is a sample string";
	const char* pch7 = strchr(str7,'T');
	const char dest7[] = "This is a sample string";
	EXPECT_STREQ(pch7, dest7);
	const char* strstr = "Hello, world!";
    EXPECT_EQ(String::strchr(strstr, 'w'), strstr + 7);
    EXPECT_EQ(String::strchr(strstr, 'H'), strstr);
    EXPECT_EQ(String::strchr(strstr, 'z'), nullptr);
}

TEST(StringFunction, strstr) {
    const char str[] = "This is a sample string";
	const char* pch = strstr(str,"string");
	const char dest[] = "string";
	EXPECT_STREQ(pch, dest);
	const char str1[] = "abc";
	const char* pch1 = strstr(str1,"bc");
	const char dest1[] = "bc";
	EXPECT_STREQ(pch1, dest1);
	const char str2[] = "a";
	const char* pch2 = strstr(str2,"a");
	const char dest2[] = "a";
	EXPECT_STREQ(pch2, dest2);
	const char str3[] = "";
	const char* pch3 = strstr(str3,"hello");
	EXPECT_STREQ(pch3, NULL);
	const char str4[] = "";
	const char* pch4 = strstr(str4,"");
	const char dest4[] = "";
	EXPECT_STREQ(pch4, dest4);
	const char str5[] = "Hello There";
	const char* pch5 = strstr(str5,"t");
	EXPECT_STREQ(pch5, NULL);
	const char str6[] = "Hello There";
	const char* pch6 = strstr(str6,"Hellb");
	EXPECT_STREQ(pch6, NULL);
	const char str7[] = "abc";
	const char* pch7 = strstr(str7,"");
	const char dest7[] = "abc";
	EXPECT_STREQ(pch7, dest7);
	const char str8[] = "abc";
	const char* pch8 = strstr(str8,"abcdef");
	EXPECT_STREQ(pch8, NULL);
	const char* strstr = "Hello, world!";
    EXPECT_EQ(String::strstr(strstr, "world"), strstr+ 7);
    EXPECT_EQ(String::strstr(strstr, ""), strstr);
    EXPECT_EQ(String::strstr(strstr, "foo"), nullptr);
    EXPECT_EQ(String::strstr(strstr, "Hello"), strstr);
    EXPECT_EQ(String::strstr(strstr, "world!"), strstr + 7);
}
