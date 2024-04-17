#include <gtest/gtest.h>
#include <sstream>
#include "word_count.hpp"

using namespace std;

TEST(WordCount, ToLowercase) {
	string test = "Hello";
	string test1 = "hEllo";
	string test2 = "hello";
	to_lowercase(test);
	to_lowercase(test1);
	to_lowercase(test2);
	EXPECT_STREQ("hello", test.c_str());
	EXPECT_STREQ("hello", test1.c_str());
	EXPECT_STREQ("hello", test2.c_str());
}
TEST(WordCount, LoadStopWords) {
	stringstream test("Hello bye");
	const auto stop_words = load_stopwords(test);
	EXPECT_TRUE(stop_words.contains("hello"));
	EXPECT_FALSE(stop_words.contains("byebye"));
	stringstream test2("");
	const auto stop_words2 = load_stopwords(test2);
	EXPECT_FALSE(stop_words2.contains("hi"));
}
TEST(WordCount, CountWords) {
	stringstream test("aa bb aa cc");
	const auto counts = count_words(test, {});
	EXPECT_EQ(counts.at("aa"), 2);
	EXPECT_EQ(counts.at("bb"), 1);
	EXPECT_EQ(counts.at("cc"), 1);
	EXPECT_FALSE(counts.contains("dd"));
	stringstream test2("$");
	const auto counts2 = count_words(test2, {});
	EXPECT_TRUE(counts2.contains("$"));
}
TEST(WordCount, OutputWordCounts) {
	map<string, int> word_counts;
	word_counts["aa"] = 1;
	word_counts["bb"] = 2;
	word_counts["cc"] = 3;
	stringstream output;
	output_word_counts(word_counts, output);
	EXPECT_STREQ(output.str().c_str(), "aa 1\nbb 2\ncc 3\n");
	map<string, int> word_counts2;
	stringstream output2;
	output_word_counts(word_counts2,output2);
	EXPECT_STREQ(output2.str().c_str(), "");
}
