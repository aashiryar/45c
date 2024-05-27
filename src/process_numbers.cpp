#include <fstream>
#include <iostream>
#include <iosfwd>
#include "process_numbers.hpp"
#include <vector>
#include <iterator>

void split_odd_even(std::istream& numbers, std::ostream& odds, std::ostream& evens) {
	auto is_odd = [](int num){return num%2 != 0;};
	auto is_even = [](int num){return num%2 == 0;};
	std::vector<int> num{std::istream_iterator<int>{numbers}, std::istream_iterator<int>{}};
	std::sort(num.begin(), num.end());
	std::ostream_iterator<int> odds_out(odds, " ");
	std::ostream_iterator<int> evens_out(evens, "\n");
	std::copy_if(num.begin(), num.end(), odds_out, is_odd);
	odds << std::endl;
	std::copy_if(num.begin(), num.end(), evens_out, is_even);
}
