#include<iostream>
using namespace std;
int main()
{
    string arr;
    getline(cin,arr);
    string part;
    cin>>part;
    while(arr.length()!=0 && arr.find(part)<arr.length()){
        arr.erase(arr.find(part),part.length());
    }
    cout<<arr;
}