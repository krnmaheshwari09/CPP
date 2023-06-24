#include<iostream>
using namespace std;
void rev(char arr[],int s,int e){
    if(s>e){
        return ;
    }
    char t = arr[s];
    arr[s] = arr[e];
    arr[e] = t;
    rev(arr,s+1,e-1);
}
bool ispalindrome(char arr[],int s,int e){
    if(s>e){
        return true;
    }
    if(arr[s] != arr[e]){
        return false;
    }else{
        return ispalindrome(arr,s+1,e-1);
    }
}
int main()
{
    string str = "abcde";
    int size = 5;
    rev(&str[0],0,size-1);
    cout<<str;
}