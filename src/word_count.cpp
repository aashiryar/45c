
#include "word_count.hpp"
#include <iostream>
#include <iosfwd>
#include <map>
#include <set>
#include <string>

void to_lowercase(std:: string& str) {
	std::string nstr = "";
	for (auto x: str) {
		nstr +=(char)tolower(x);
	}
	str = nstr;
}
std::set<std::string> load_stopwords(std::istream& stopwords) {
	std::set<std::string> words;
	std::string word;
	while (stopwords >> word) {
		to_lowercase(word);
		words.insert(word);
	}
	return words;
}
std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords) {
	std::map<std::string, int> word_counts;
	std::string word;
	while (document >> word){
		to_lowercase(word);
		if(stopwords.find(word) == stopwords.end()) {
			if (word_counts.count(word) != 0) {
				word_counts[word]++;
			}
			else {
				word_counts.insert({word, 1});
			}
		}
	}
	return word_counts;
}
void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output) {
	for (const auto& elem: word_counts) {
		output << elem.first << " " << elem.second << "\n";
	}
}


