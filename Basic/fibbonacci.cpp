#include<iostream>
using namespace std;
int main()
{
    int n,num1=0,num2=1;
    cout<<"Enter the number of terms:";
    cin>>n;
    cout<<num1<<" "<<num2<<" ";
    for(int i=0;i<n-2;i++){
        int nt = num1+num2;
        cout<<nt<<" ";
        num1 = num2;
        num2 = nt;
    }
}