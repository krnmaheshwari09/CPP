#include<iostream>
using namespace std;
int main()
{
    string arr;
    getline(cin,arr);
    int count[26] = {0};
    for(int i=0;i<arr.length();i++){
        int number = 0;
        if(arr[i]>='a' && arr[i]<='z'){
            number = arr[i] - 'a';
        }else{
            number = arr[i] - 'A';
        }
        count[number]++;
    }
    int max = -1,ans = 0;
    for(int i=0;i<26;i++){
        if(max < count[i]){
            ans = i;
            max = count[i];
        }
    }
    char maxChar = ans + 'a';
    cout<<maxChar;
}