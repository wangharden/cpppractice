#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;

int  fun(int &n,int &sum){
	int i=10;
	int rest =0;
	do{
		rest=n/i;
		i=i*10;}while(rest!=0);
	int re=1;
	i=i/100;
	for(i;i>0;i=i/10){
		sum=sum+(n/i)*re;
		n=n%i;
		re=re*10;}
	return sum;
	}

int main(){
	int n;
	do{
		cout<<"please enter a positive integer:";
		cin>>n;}while(n<0);
	int sum=0;
	fun(n,sum);
	cout<<sum<<endl;
	if (sum==n)
	cout<<"yes";
	else cout<<"no";
	return 0;}