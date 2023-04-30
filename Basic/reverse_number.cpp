#include<iostream>
using namespace std;
int main()
{
    int num,rev_num = 0;
    cout<<"Enter a number: ";
    cin>>num;
    while(num!=0){
        rev_num = rev_num*10 + (num%10);
        num = num/10;
    }
    cout<<"Reverse of number is "<<rev_num;
}