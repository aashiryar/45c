#include "mapset.hpp"
#include <iosfwd>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <sstream>

std::string to_lowercase(const std::string& str) {
	std::string lower = str;
	std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
	return lower;
}
std::set<std::string> load_stopwords(std::istream& stopwords) {
	std::set<std::string> words;
	std::for_each(std::istream_iterator<std::string>(stopwords), std::istream_iterator<std::string>(), [&words](const std::string& word){words.insert(to_lowercase(word));});
	return words;
}
std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords) {
	std::map<std::string, int> word_counts;
	std::string word;
	std::for_each(std::istream_iterator<std::string>(document), std::istream_iterator<std::string>(),[&word_counts, &stopwords](const std::string& word) {
		std::string lword = to_lowercase(word);
		if (stopwords.find(lword) == stopwords.end()){
			if (word_counts.count(lword) != 0) {
				word_counts[lword]++;
			}
			else {
				word_counts.insert({lword,1});
			}
		}
	});
	return word_counts;
}
void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output) {
	for(const auto&[word, count] : word_counts)
		{output<<word<<" "<<count<<std::endl;}
}

