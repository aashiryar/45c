#include <iostream>
#include "coins.hpp"

using namespace std;

int main() {
	Coins piggyBank = Coins(50,50,50,50);
	Coins pocket = Coins(8,3,6,8);
	cout << "Initial piggy bank: " << piggyBank << endl;
	cout << "Initial pocket: " << pocket << std::endl;
	Coins coins_for_chips = coins_required_for_cents(149);
	if (pocket.has_exact_change_for_coins(coins_for_chips)) {
		pocket.extract_exact_change(coins_for_chips);
		cout << "Bought chips using pocket" << endl;
		cout << "Chips required the coins: " << coins_for_chips << endl;
		cout << "Pocket after paying for chips: " << pocket << endl;
	}
	else {
		cout << "Not enough coins."<<endl;
	}
	Coins transfer_coins = Coins(16,0,1,0);
	piggyBank.extract_exact_change(transfer_coins);
	pocket.deposit_coins(transfer_coins);
	cout << "Transferring money to pocket" << endl;
	cout << "Coins for transfer: " << transfer_coins << endl;
	cout << "Pocket: " << pocket << endl;
	cout << "Piggy bank: " << piggyBank << endl;
	Coins change = Coins(10,10,10,10);
	piggyBank.deposit_coins(change);
	cout << "Transferring sofa change to piggy bank" << endl;
	cout << "Sofa: " << change << endl;
	cout << "Piggy bank: " << piggyBank << endl;
	int total = piggyBank.total_value_in_cents();
	cout << "Piggy bank total: ";
	print_cents(total, cout);
	cout << endl;
	return 0;
}
