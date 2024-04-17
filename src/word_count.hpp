#ifndef WORD_COUNT_HPP
#define WORD_COUNT_HPP

#include <iosfwd>
#include <map>
#include <set>
#include <string>
#include <iostream>

inline void to_lowercase(std::string& str) {
	std::string nstr = "";
	for (auto x: str) {
		nstr += (char)tolower(x);
	}
	str = nstr;
}
inline std::set<std::string> load_stopwords(std::istream& stopwords) {
	std::set<std::string> words;
	std::string word;
	while (stopwords >>  word) {
		to_lowercase(word);
		words.insert(word);
	}
	return words;
}
inline std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords) {
	std::map<std::string, int> words_counts;
	std::string word;
	while (document >> word) {
		to_lowercase(word);
		if (stopwords.find(word) == stopwords.end()) {
			if (words_counts.count(word) != 0){
				words_counts[word] ++;
			}
			else {
				words_counts.insert({word, 1});
			}
		}
	}
	return words_counts;

}	
inline void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output) {
	for (const auto& elem: word_counts) {
		output << elem.first << " " << elem.second << "\n";
	}
}

#endif
