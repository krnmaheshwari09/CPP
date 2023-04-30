#include<iostream>
using namespace std;
int main()
{
    int num,i=2,count = 0;
    cout<<"Enter a number :\n";
    cin>>num;
    while(i<num){
        if(num%i==0){
            cout<<"It is not a prime number.";
            count = 1;
            break;
        }
        i++;
    }
    if(count==0){
        cout<<"It is a prime number.";
    }
}