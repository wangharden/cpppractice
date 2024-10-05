#include<stdio.h>
#include<iostream>
#include<limits>
using namespace std;
int main() {
	int a, b;
	std::cout << "please enter a:";
	std::cin >> a;
	std::cout << "please enter b:";
	std::cin >> b;
	int n = a - b;
	int c=0;
	int biggest = numeric_limits<int>::min();
	int m;
	if (n < 0) {
		 m = b;
	}
	else {
		 m = a;
	}
	for (int i = 2;i < m;i++) {
		if (a % i == 0 && b % i == 0) {
			if (i > biggest) biggest = i;
		}
		c++;
	}
	if (c == 0) {
		std::cout << "they do not have common divisor";
	}
	else {
		std::cout << "the biggest common divisor is :" << biggest;
	}
	return 0;
}