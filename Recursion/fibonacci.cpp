#include<iostream>
using namespace std;
void fibonacci(int n,int a = 0,int b = 1){
    if(n==0){
        cout<<"0"<<endl;
    }else if(n==1){
        cout<<b<<endl;
    }else{
        int t = b;
        b = a+b;
        a = t;
        fibonacci(n-1,a,b);
    }
}
int main()
{
    int n;
    cin>>n;
    fibonacci(n);
}