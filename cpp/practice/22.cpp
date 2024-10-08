#include<iostream>
void fun(int *param){
    *param=*param+1;

}
int *p1=nullptr;
int main(){
    int x=3;
    int*p=&x;
    fun(p);
    int y= 0;
    *p = y;
    p =&y;
    std::cout<<"x="<<x<<std::endl;
    std::cout<<p<<std::endl;
    return 0;
};