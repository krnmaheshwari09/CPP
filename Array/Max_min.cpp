#include<iostream>
using namespace std;
int maximum(int num[],int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(num[i]>max)
            max = num[i];
    }
    return max;
}
int minimum(int num[],int n){
    int min = INT_MAX;
    for(int i=0;i<n;i++){
        if(min>num[i])
            min = num[i];
    }
    return min;
}
int main()
{
    int arr[5];
    cout<<"Enter five numbers : ";
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    int max = maximum(arr,5);
    int min = minimum(arr,5);
    cout<<"maximum number = "<<max<<endl;
    cout<<"minimum number = "<<min<<endl;    
}