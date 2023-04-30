#include<iostream>
using namespace std;
int fact(int n){
    int factorial=1;
    for(int i=1;i<=n;i++){
        factorial = factorial*i;
    }
    return factorial;
}
int nCr(int n,int r){
    int nume = fact(n);
    int deno = fact(r)*fact(n-r);
    return (nume/deno);
}
int main()
{
    int n,r;
    cout<<"Enter the value of n and r in nCr : ";
    cin>>n >>r;
    cout<<(nCr(n,r));
}