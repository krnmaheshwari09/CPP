#include<iostream>
using namespace std;


// int binarySearch(int arr[],int size,int num){
    // int start = 0,end = size-1;
    // int mid;
    // while(start<=end){
    //     //mid = (start + end)/2;
    //     //Error se bachne ke liye
    //     mid = start + (end-start)/2;
    //     if(arr[mid]==num){
    //         return mid;
    //     }
    //     if(arr[mid]>num){
    //         end = mid-1;
    //     }
    //     else{
    //         start= mid +1;
    //     }
    // }
    // return -1;
// }
// int main()
// {
//     int size;
//     cout<<"Enter size of array : ";
//     cin>>size;
//     int arr[size];
//     cout<<"Enter elements of array iñ monotonically increasing format : ";
//     for(int i=0;i<size;i++){
//         cin>>arr[i];
//     }
//     int num;
//     cout<<"Enter number you want to search : ";
//     cin>>num;
//     int index = binarySearch(arr,size,num);
//     cout<<"Index of number in array = "<<index;
// }


//First and last occurence of a number and total number of occurence.

// int firstOccurence(int arr[],int n,int num){
//     int start = 0,end = n-1;
//     int mid,ans = -1;
//     while(start<=end){
//         //mid = (start + end)/2;
//         //Error se bachne ke liye
//         mid = start + (end-start)/2;
//         if(arr[mid]==num){
//             ans = mid;
//             end = mid -1;
//         }
//         if(arr[mid]>num){
//             end = mid-1;
//         }
//         else{
//             start= mid +1;
//         }
//     }
//     return ans;
// }
// int lastOccurence(int arr[],int n,int num){
//     int start = 0,end = n-1;
//     int mid,ans = -1;
//     while(start<=end){
//         //mid = (start + end)/2;
//         //Error se bachne ke liye
//         mid = start + (end-start)/2;
//         if(arr[mid]==num){
//             ans = mid;
//             start = mid +1;
//         }
//         if(arr[mid]>num){
//             end = mid-1;
//         }
//         else{
//             start= mid +1;
//         }
//     }
//     return ans;
// }
// int main(){
//     int even[7]= {1,2,3,3,3,3,5};
//     cout<<firstOccurence(even,7,3)<<" "<<lastOccurence(even,7,3)<<endl;
//     cout<<((lastOccurence(even,7,3)-firstOccurence(even,7,3))+1);
// }


//Peak index of in a array.

// int peakIndex(int arr[],int n){
//     int s = 0, e = n-1;
//     int mid;
//     while(s<e){
//         mid = s +(e-s)/2;
//         if(arr[mid]<arr[mid+1]){
//             s = mid+1;
//         }
//         else{
//             e = mid;
//         }
//     }
//     return s;
// }
// int main(){
//     int arr[6] ={1,2,3,4,3,1};
//     cout<<peakIndex(arr,6);
// }

//to find pivot number in an array and also find target number from circulated monotonic array.

// int pivotNumber(int arr[],int n){
//     int s=0,e = n-1,mid;
//     while(s<e){
//         mid = s + (e-s)/2;
//         if(arr[mid]>=arr[0]){
//             s = mid+1;
//         }else{
//             e = mid;
//         }
//     }
//     return s;
// }
// int getTarget(int arr[],int n,int pivot,int key){
//     int s,e,mid;
//     if(arr[pivot]<=key && key<=arr[n-1]){
//         s = pivot;
//         e = n-1;
//     }
//     else{
//         s=0;
//         e = pivot-1;
//     }
//     while(s<=e){
//         mid = s + (e-s)/2;
//         if(arr[mid]==key){
//             return mid;
//         }else if(arr[mid]<key){
//             s = mid + 1;
//         }else{
//             e = mid-1;
//         }
//     }
//     return -1; 
// }
// int main()
// {
//     int arr[5] = {8,10,17,1,3};
//     int a = pivotNumber(arr,5);
//     cout<<(a)<<endl<<getTarget(arr,5,a,3)<<endl;
// }

//find square root of a number to the nearest integer.

int integerPart(int n){
    int s = 0,e = n;
    long long int mid,ans;
    while(s<=e){
        mid = s + (e-s)/2;
        if(mid*mid == n){
            return mid;
        }else if(mid*mid<n){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid-1;
        }
    }
    return ans;
}
double sqrt(int n,int decim,int part){
    double factor = 1;
    double ans = part;
    for(int i=0;i<decim;i++){
        factor = factor/10;
        for(double j=part;j*j<n;j+=factor){
            ans = j;
        }
    }
    return ans;
}
int main()
{
    int num = 37;
    int part = integerPart(num);
    double ans = sqrt(num,3,part);
    cout<<ans<<endl;
}

