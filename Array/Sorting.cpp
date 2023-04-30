#include<iostream>
#include<algorithm>
using namespace std;

//Selection sort
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

//Bubble Sort
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool count = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                count = true;
            }
        }
        if(count == false){
            break;
        }
    }
}

// insertion sort
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int t = arr[i],j=i-1;
        for(;j>=0;j--){
            if(arr[j]>t){
                arr[j+1]=arr[j];
            }else{
                break;
            }
        }
        arr[j+1]=t;
    }
}
int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // selectionSort(arr,n);
    // bubbleSort(arr,n);
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}