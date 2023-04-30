#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



// reverse of array after the given index.

// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int m ,t= n-1;
//     cin>>m;
//     int s=m+1;
//     while(s<=t){
//         swap(arr[s],arr[t]);
//         t--;
//         s++;
//     }
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }

// merge sorted array.

// void input(vector<int> &v,int n){
//     for(int i=0;i<n;i++){
//         int arr;
//         cin>>arr;
//         v.push_back(arr);
//     }
// }
// int main(){
//     int n,m;
//     cout<<"Enter sizes of two arrays : ";
//     cin>>n >>m;
//     vector<int> arr1,arr2;
//     cout<<"Enter elements of first array : ";
//     input(arr1,n);
//     cout<<"Enter elements of second array : ";
//     input(arr2,m);
//     vector<int> ans;
//     int i=0,j=0,count =0;
//     while(i<n || j<m){
//         if(arr1[i]==0){
//             i++;count++;
//         }
//         else if(arr2[j]==0){
//             j++;count++;
//         }
//         else{
//             if(arr1[i]<=arr2[j] && i!=n){
//                 ans.push_back(arr1[i]);
//                 i++;
//             }
//             else if(arr2[j]<arr1[i] && j!=m){
//                 ans.push_back(arr2[j]);
//                 j++;
//             }else if(i==n){
//                 ans.push_back(arr2[j]);
//                 j++;
//             }else if(j==m){
//                 ans.push_back(arr1[i]);
//                 i++;
//             }
//         }
//     }
//     while(count--){
//         ans.push_back(0);
//     }
//     for(auto i:ans){
//         cout<<i<<" ";
//     }
// }

// rotate a array by nth time. 

int main(){
    int n,k;
    cout<<"Enter size of array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements of array : ";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout<<"Enter number of rotation : ";
    cin>>k;
    int temp;
    while(k--){
        temp = arr[n-1];
        int i = n-1;
        while(i){
            arr[i] = arr[i-1];
            i--;
        }
        arr[0] = temp;
    }
    for(int i:arr){
        cout<<i<<" ";
    }
}

