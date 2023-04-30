#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,binary=0;
    cin>>n;
    int i=0;
    while(n!=0){
        int bit = n&1;
        binary = bit*pow(10,i) + binary;
        n = n>>1;
        i++;
    }
    cout<<binary;
}