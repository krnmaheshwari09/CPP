#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int bn,num=0;
    int i=0;
    cin>>bn;
    while(bn>0){
        if(bn%10 == 1){
            num = pow(2,i) + num;
        }
        bn = bn/10;
        i++;
    }
    cout<<num;
}