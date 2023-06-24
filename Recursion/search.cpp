#include<iostream>
using namespace std;
bool linear_search(int arr[],int size,int k){
    if(size == 0){
        return false;
    }
    if(arr[0] == k){
        return true;
    }else{
        bool remaining_part = linear_search(arr+1,size-1,k);
        return remaining_part;
    }
}
bool binary_search(int arr[],int s,int e,int k){
    if(s>e){
        return false;
    }
    int mid = s + (e-s)/2;
    if(arr[mid] == k){
        return true;
    }
    if(arr[mid] < k){
        return binary_search(arr,mid+1,e,k);
    }else{
        return binary_search(arr,s,mid-1,k);
    }
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int key = 5;
    bool ispresent;
    // ispresent = linear_search(arr,size,key);
    ispresent = binary_search(arr,0,size-1,key);
    if(ispresent){
        cout<<"Present";
    }else{
        cout<<"Absent";
    }
}