#include<iostream>
using namespace std;
int main()
{
    int a,b;
    char opr;
    cout<<"Enter two numbers: ";
    cin>>a >>b;
    cout<<"Enter operator (+|-|/|*): ";
    cin>>opr;
    switch (opr){
        case '+': cout<<"Sum of numbers = "<<(a+b);
                break;
        case '-': cout<<"Difference of numbers = "<<(a-b);
                break;
        case '*': cout<<"Multiplication of numbers = "<<(a*b);
                break;
        case '/': cout<<"Division of a by b = "<<(a/b);
                break;
        default : cout<<"You enter wrong operator.";
    }
}