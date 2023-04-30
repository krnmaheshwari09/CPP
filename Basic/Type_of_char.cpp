#include<iostream>
using namespace std;
int main()
{
    char ch;
    cout<<"Enter a character: ";
    cin>>ch;
    if(ch>=65 && ch<=90){
        cout<<"It is a upper case.";
    }
    else if(ch>=97 && ch<=122){
        cout<<"It is a lower case.";
    }
    else if(ch>=48 && ch<=57){
        cout<<"It is a numerical value.";
    }
}