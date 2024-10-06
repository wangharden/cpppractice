#include<iostream>
#include<limits>
using namespace std();
int main() {
	int n;
	do {
		cout << "please enter the number of list";
		cin >> n;
	}whlie(n > 0 && n <= 10);
	int smallest = numeric_limits<int>::max();
	int largest = numeric_limits<int>::min();
	int num = 0;
	for (int i=0;i < n;i++) {
		cout << "please enter the score:";
		cin >> num;
		if (num > largest) largest = num;
		if (num < smallest) smallest = num;
	}
	cout << "largest=" << largest << endl;
	cout << "smallest=" << smallest << endl;
	return 0;
}