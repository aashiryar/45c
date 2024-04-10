constexpr int STK_MAX = 1000;

class Stack
{
	int topv;
	char buf[STK_MAX];
public:
	Stack() {
		topv = 0;
	}
	void push(char c) {
		if (topv != STK_MAX ) {
			buf[topv] = c;
			topv++;
		}
	}
	char pop() {
		if(topv != 0){
			return buf[--topv];
		}
		else {
			return '@';
		}

	}
	char top() {
		if (topv != 0) {
			return buf[topv];
		}
		else {
			return '@';
		}
	}
	bool isEmpty() {
		if (topv == 0) {
			return true;
		}
		return false;
	}
	bool isFull() {
		if (topv == STK_MAX){
			return true;
		}
		return false;
	}
};
void push_all(Stack & stk, string line){
	for (char ch: line) {
		stk.push(ch);
	}
	
}
void pop_all(Stack & stk) {
	while(!stk.isEmpty()) {
		cout << stk.pop();
	}
	cout <<"\n";
}
