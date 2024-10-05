#include<iostream>
using namespace std;

int main(){
	int n;
	int sum;
	float average;
	int i=1;
	while(true){
	cout<<"please enter an integer less than 1000:";
	cin>>n;
	if(n==1000){
		break;}
	else
		{++i;
		sum+=n;
		average=static_cast<float>(sum)/(i-1);}
		}
	cout<<"sum="<<sum<<endl;
	cout<<"average="<<average<<endl;
	cout<<i;
	return 0;}