#include <iostream>
using namespace std;
#include "convert_knots.hpp"

int main() {
	int knots = 1;
	cout << "Enter a speed in knots: ";
	cin >> knots;
	cout << "Speed in miles per min: "
		 << knots_to_miles_per_minute(knots)
		 << endl;
	return 0;

}
