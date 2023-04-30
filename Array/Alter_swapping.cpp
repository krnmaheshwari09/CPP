#include<iostream>
using namespace std;
int main()
{
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter elemnets of array : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    //swapping
    for(int i=1;i<size;i+=2){
        int t = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = t;
    }
    cout<<"After swapping : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}