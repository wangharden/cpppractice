#include<iostream>
using namespace std;

int main(){
	int n;
	int posnum=0;
	int negativenum=0;
	while(true){
		cout<<"please enter an integer:";
		cin>>n;
		if(n==0){
			break;}
		if(n<0) {negativenum+=1;}
		if(n>0) {posnum+=1;}}
	cout<<"the number of negative is :"<<negativenum<<endl;
	cout<<"the number of positive is :"<<posnum<<endl;
	return 0;}