#include<iostream>
using namespace std;

// find the no. of distinct ways to reach the top of stairs.
int countways(int n){
    if(n<0){
        return 0;
    }if(n==0){
        return 1;
    }
    int ans = countways(n-1) + countways(n-2);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<countways(n)<<endl;
}