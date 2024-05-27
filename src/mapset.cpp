#include "mapset.hpp"
#include <iosfwd>
#include <map>
#include <set>
#include <string>
#include <iostream>

std::string to_lowercase(const std::string& str) {
	std::string lower = str;
	std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
	return lower;
}
std::set<std::string> load_stopwords(std::istream& stopwords) {
	std::set<std::string> words;
	std::string word;
	while(stopwords >> word) {
		words.insert(to_lowercase(word));
	}
	return words;
}
std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords) {
	std::map<std::string, int> word_counts;
	std::string word;
	while (document >> word) {
		word = to_lowercase(word);
		if (stopwords.find(word) == stopwords.end()){
			if (word_counts.count(word) != 0) {
				word_counts[word]++;
			}
			else {
				word_counts.insert({word,1});
			}
		}
	}
	return word_counts;
}
void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output) {
	for(const auto&[word, count] : word_counts)
		{output<<word<<" "<<count<<std::endl;}
}

