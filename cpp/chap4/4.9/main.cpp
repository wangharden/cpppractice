#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int a,b;
	int i;
	int c=0;
	cout<<"please enter a:"<<endl;
	cin>>a;
	cout<<"please enter b:"<<endl;
	cin>>b;
	for(i=2;i<100;i++){
		if(a%i==0 && b%i==0) {
		cout<<i<<" ";
		c++;		}
			}
	if (c==0) cout<<"they do not have common divisors.";
	return 0;}