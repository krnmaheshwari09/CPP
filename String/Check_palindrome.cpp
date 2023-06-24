#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
    string arr1;
    getline(cin, arr1);
    for(auto& c:arr1){
        c = tolower(c);
    }
    string arr = "";
    for(int i=0;i<arr1.length();i++){
        if((arr1[i]>='a' && arr1[i]<='z')||(arr1[i]>='0' && arr1[i]<='9')){
            arr.push_back(arr1[i]);
        }
    }
    int s=0,e = arr.length() - 1;
    while(s<=e){
        if(arr[s] != arr[e]){
            cout<<"it is not a palindrome.";
            exit(0);
        }
        s++;
        e--;
    }
    cout<<"it is a palindrome.";
}