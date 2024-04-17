#ifndef COINS_HPP
#define COINS_HPP
#include <iosfwd>
#include <iostream>

constexpr int CENTS_PER_QUARTER = 25;
constexpr int CENTS_PER_DIME = 10;
constexpr int CENTS_PER_NICKEL = 5;

class Coins {
public:
	Coins(int q, int d, int n, int p) : quarters(q), dimes(d), nickels(n), pennies(p) {}
	void deposit_coins(Coins& coins) {
		quarters+=coins.quarters;
		dimes+=coins.dimes;
		nickels+=coins.nickels;
		pennies+=coins.pennies;
		coins = Coins(0,0,0,0);
	}
	bool has_exact_change_for_coins(const Coins& coins){
		if (quarters >= coins.quarters && dimes >= coins.dimes && nickels >= coins.nickels && pennies >= coins.pennies) {
			return true;
		}
		else {
			return false;
		}
	}
	Coins extract_exact_change(const Coins& coins) {
		if (has_exact_change_for_coins(coins)) {
			quarters -= coins.quarters;
			dimes -= coins.dimes;
			nickels -= coins.nickels;
			pennies -= coins.pennies;
			//return Coins(quarters, dimes, nickels, pennies);
			return coins;
		}
		else {
			return Coins(0,0,0,0);
		}
	}
	int total_value_in_cents() const {
		int total = 0;
		total += quarters*CENTS_PER_QUARTER;
		total += dimes*CENTS_PER_DIME;
		total += nickels*CENTS_PER_NICKEL;
		total += pennies;
		return total;
	}
	void print(std::ostream& out) const {
		out << quarters << " quarters, " 
			<< dimes << " dimes, " 
			<< nickels << " nickels, " 
			<< pennies << " pennies";
	}
	bool operator==(const Coins& other) const = default;
private:
	int quarters, dimes, nickels, pennies;
};

inline std::ostream& operator <<(std::ostream& out, const Coins& coins) {
	coins.print(out);
	return out;
}
inline Coins coins_required_for_cents(int amount_in_cents) {
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int pennies = 0;
	while (amount_in_cents>=CENTS_PER_QUARTER) {
		amount_in_cents -= CENTS_PER_QUARTER;
		quarters += 1;
	}
	while (amount_in_cents>=CENTS_PER_DIME) {
		amount_in_cents -= CENTS_PER_DIME;
		dimes += 1;
	}
	while (amount_in_cents>=CENTS_PER_NICKEL) {
		amount_in_cents -= CENTS_PER_NICKEL;
		nickels+= 1;
	}
	pennies = amount_in_cents;
	Coins coins = Coins(quarters, dimes, nickels, pennies);
	return coins;
}
inline void print_cents(int cents, std::ostream& out) {
	out << "$" << cents/100 << "." << cents%100/10 << cents%10;
}
inline Coins ask_for_coins(std::istream& in, std::ostream& out) {
	int quarters;
	out << "Quarters? ";
	in >> quarters;
	int dimes;
	out << "Dimes? ";
	in >> dimes;
	int nickels;
	out << "Nickels? ";
	in >> nickels;
	int pennies;
	out << "Pennies? ";
	in >> pennies;
	Coins coins = Coins(quarters, dimes, nickels, pennies);
	return coins;
}
inline void print_coins_menu(std::ostream& out) {
    out << "Coins Menu" << std::endl;
    out << std::endl;
    out << "1. Deposit Change" << std::endl;
    out << "2. Extract Change" << std::endl;
    out << "3. Print Balance" << std::endl;
    out << "4. Exit" << std::endl;
    out << std::endl;
}
inline void extract_change(Coins& coins, std::istream& in, std::ostream& out) {
   	Coins extract= ask_for_coins(in, out);
    if (coins.has_exact_change_for_coins(extract)) {
        coins.extract_exact_change(extract);
        out << "Thank you!" << std::endl;
    } 
	else {
        out << "ERROR: Insufficient Funds" << std::endl;
    }
    out << std::endl;
}

inline void print_balance(const Coins& coins, std::ostream& out) {
    int total= coins.total_value_in_cents();
    out << "$";
    print_cents(total, out);
    out << std::endl;
    out << "Thank you!" << std::endl;
    out << std::endl;
}
inline void deposit_change(Coins& coins, std::istream& in, std::ostream& out) {
    Coins deposit = ask_for_coins(in, out);
    coins.deposit_coins(deposit);
    out << "Thank you!" << std::endl;
    out << std::endl;
}
inline void coins_menu(std::istream& in, std::ostream& out) {
	Coins coins = Coins(0,0,0,0);
    int choice = 0;
    while (choice != 4) {
        print_coins_menu(out);
        out << "User Input: ";
        in >> choice;
        if (choice == 1) {
        	deposit_change(coins, in, out);
        }
        else if (choice ==2) {
       		extract_change(coins, in, out);
        }
		else if (choice ==3) {
			print_balance(coins, out);
		}
        else if (choice == 4) {
			out << " ";
		}
        else {
			out << "ERROR: Invalid Command" << std::endl;
                out << std::endl;
        }
	}
}

#endif
