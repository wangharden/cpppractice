#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;

const int N = 256;
int main(){
	char buff[N] = { 0 };
	do
	{
		cout<<"please enter a positive integer:";
		cin>>buff;
	}while(buff[0]=='-');
	for (int i = N - 1; i >= 0; --i) {
		if (buff[i]) cout << buff[i];
	}
	return 0;
}