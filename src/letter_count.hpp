#include <iostream>

int char_to_index(char ch) {
	if (isupper(ch)) {
		return ch - 'A';
	}
	else {
		return ch - 'a';
	}
}
char index_to_char(int i) {
	if (i>96) {
		return char(i - 97);
	}
	else {
		return char(i - 65);
	}
}
void count(string s, int counts[]){
	for (char ch : s) {
		if (isalpha(ch)){
			int index = char_to_index(ch);
			counts[index]++;
		}
	}
}
void print_counts(int counts[], int len) {
	for (int i = 0; i<len; i++) {
		std::cout << index_to_char(i) << " " << counts[i] << std::endl; 
	}
}
