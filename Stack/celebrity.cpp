#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int celebrity(vector<vector<int>>& arr,int n){
    stack<int> s;
    for(int i = 0;i<n;i++){
        s.push(i);
    }
    while(s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(arr[a][b] == 1){
            s.push(b);
        }else{
            s.push(a);
        }
    }
    int candidate = s.top();
    int rowCount = 0;
    for(int i = 0;i<n;i++){
        if(arr[candidate][i] == 0){
            rowCount++;
        }
    }
    if(rowCount != n){
        return -1;
    }
    int colCount = 0;
    for(int i = 0;i<n;i++){
        if(arr[i][candidate] == 1){
            colCount++;
        }
    }
    if(colCount != n-1){
        return -1;
    }

    return candidate;
}
int main(){
    int n = 3;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int ans = celebrity(arr,n);
    cout<<ans;
}
