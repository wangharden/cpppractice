#include<stdio.h>
#include<limits>
using namespace std;
int main() {
	int a, b;
	cout << "please enter a:";
	cin >> a;
	cout << "please enter b:";
	cin >> b;
	int n = a - b;
	int biggest = numeric_limits<int>::min();
	if (n < 0) {
		int m = b;
	}
	else {
		int m = a;
	}
	for (int i = 2;i < m;i++) {
		if (a % i == 0 && b % i == 0) {
			if (i > biggest) biggest = i;
		}
		int c = 0;
		c++;
	}
	if (c == 0) {
		cout << "they do not have common divisor";
	}
	else {
		cout << "the biggest common divisor is :" << biggest;
	}
	return 0;
}