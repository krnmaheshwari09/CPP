#include<iostream>
using namespace std;

// bubble sort.
void sortArray(int arr[],int n){
    if(n==0||n==1){
        return ;
    }

    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    sortArray(arr,n-1);
}

// Merge sort.
void merge(int arr[],int s, int e){
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    // copy values
    int k = s;
    for(int i = 0;i<len1;i++){
        first[i] = arr[k++];
    }
    k = mid + 1;
    for(int i = 0;i<len2;i++){
        second[i] = arr[k++];
    }
    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    k = s;
    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[k++] = first[index1++];
        }else{
            arr[k++] = second[index2++];
        }
    }
    while(index1 < len1){
        arr[k++] = first[index1++];
    }
    while(index2 < len2){
        arr[k++] = second[index2++];
    }
}
void mergeSort(int arr[],int s,int e){
    if(s>=e){
        return ;
    }
    int mid = s + (e-s)/2;
    // left part sort karna h
    mergeSort(arr,s,mid);
    // right part ko sort karna h
    mergeSort(arr,mid+1,e);
    // merge
    merge(arr,s,e);
}

// quick sort
int partition(int arr[],int s,int e){
    int pivot = arr[s];
    int cnt = 0;
    for(int i = s+1;i<=e;i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }
    // Place pivot at right position
    int pivotIndex = s+cnt;
    swap(arr[pivotIndex],arr[s]);
    // left and right part sambhal lete h
    int i = s,j = e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[],int s, int e){
    // base case
    if(s>=e){
        return ;
    }
    // partition karna
    int p = partition(arr,s,e);
    // left part sort karo
    quickSort(arr,s,p-1);
    // right part sort karo
    quickSort(arr,p+1,e);
}
int main()
{
    int arr[] = {1,3,5,2,6};
    quickSort(arr,0,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}