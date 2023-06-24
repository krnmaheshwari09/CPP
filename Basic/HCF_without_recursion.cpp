#include<iostream>
#include<algorithm>
using namespace std;


// First Method:

// int main(){
//     int a,b;
//     cin>>a >>b;
//     int t = min(a,b);
//     b = max(a,b);
//     a = t;
//     for(int i = a;i>0;i--){
//         if(a%i==0 && b%i==0){
//             cout<<"HCF = "<<i;
//             break;
//         }
//     }
// }


// Second Method:

int hcf(int a,int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    while(a!=b){
        if(a>b)
            a = a-b;
        else
            b = b-a;
    }
    return a;
}
int main(){
    int a,b;
    cin>>a >>b;
    int ans = hcf(a,b);
    cout<<ans;
}