#include<iostream>
using namespace std;

int main(){
	int begin;
	int end;
	int n;
	cout<<"please enter the first positive integer:";
	cin>>begin;
	cout<<"please enter the second positive integer:";
	cin>>end;
	if(begin>end){
		n=begin;
		begin=end;
		end=n;}
	int i=0;
		if(begin%2==0){
			cout<<"the even list :";
			for(i=begin+1;i<end;i=i+2){
				cout<<i ;}
			cout<<endl;	
			cout<<"the odd list :";
			for(i=begin+2;i<end;i=i+2){
				cout<<i ;}
			}
		else{
			cout<<"the even list :";
			for(i=begin+2;i<end;i=i+2){
				cout<<i ;}
			cout<<endl;
			cout<<"the odd list :";
			for(i=begin+1;i<end;i=i+2){
				cout<<i ;}
			}
	return 0;}