#include<iostream>
using namespace std;
const int N = 255;
int main() {
	char buff[N] = { 0 };
	do {
		cout << "please enter an integer: ";
		cin >> buff;
	} while (buff[0] == '-');
	for (int i = N - 1;i >= 0;--i) {
		if (buff[i]) cout << buff[i];
	}
	return 0;
}