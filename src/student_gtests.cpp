#include <gtest/gtest.h>
#include <sstream>
#include "word_count.hpp"

using namespace std;

TEST(WordCount, ToLowercase) {
	string test = "Hello";
	string test1 = "hEllo";
	string test2 = "hello";
	string test3 = "hELLO world";
	to_lowercase (test); 
	to_lowercase (test1); 
	to_lowercase (test2); 
	to_lowercase (test3) ;
	EXPECT_STREQ("hello", test.c_str());
	EXPECT_STREQ("hello", test1.c_str());
	EXPECT_STREQ("hello", test2.c_str());
	EXPECT_STREQ("hello world", test3.c_str());
}
TEST(WordCount, LoadStopWords) {
	stringstream test("Hello bye");
	const auto stop_words = load_stopwords(test);
	EXPECT_TRUE (stop_words. contains ("hello"));
	EXPECT_FALSE (stop_words.contains ("byebye")); 
	stringstream test2("");
	const auto stop_words2 = load_stopwords (test2) ;
	EXPECT_FALSE (stop_words2. contains ("hi"));
	stringstream test3("hello world");
	const auto stop_words3 = load_stopwords (test3);
	EXPECT_TRUE (stop_words3.contains("hello"));
	EXPECT_TRUE (stop_words3.contains("world")) ;
	EXPECT_FALSE (stop_words3.contains("foo"));
}
TEST(WordCount, CountWords) {
	stringstream test("Aa aa bc foo bar");
	const auto counts = count_words(test, {});
	EXPECT_EQ(counts.at("aa"), 2);
	EXPECT_EQ(counts.at("bc"), 1);
	EXPECT_EQ(counts.at("foo"), 1);
	EXPECT_EQ(counts.at("bar"), 1);
	EXPECT_EQ(counts.size(), 4);
	EXPECT_FALSE(counts.contains("baz"));
	
}
TEST(WordCount, OutputWordCounts) {
	map<string, int> word_counts;
	word_counts["foo"] = 1;
	word_counts["bar"] = 5;
	word_counts["xy"] = 3;
	stringstream output;
	output_word_counts(word_counts, output);
	EXPECT_STREQ(output.str().c_str(), "bar 5\nfoo 1\nxy 3\n");
}
