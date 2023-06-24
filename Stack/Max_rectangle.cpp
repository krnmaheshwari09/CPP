#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int>&arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n-1;i>=0;i--){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int>&arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = 0;i<n;i++){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largest(vector<int>& heights,int n){
    vector<int> next(n);
    next = nextSmallerElement(heights,n);
    vector<int> prev(n);
    prev = prevSmallerElement(heights,n);

    int area = INT_MIN;
    for(int i = 0;i<n;i++){
        int l = heights[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        area = max(area,(l*b));
    }
    return area;
}
int maxArea(vector<vector<int>>& arr,int n, int m){
    int area = largest(arr[0],m);
    for(int i = 1;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j] != 0){
                arr[i][j] = arr[i][j] + arr[i-1][j];
            }else{
                arr[i][j] = 0;
            }
        }
        area = max(area,largest(arr[i],m));
    }
    return area;
}
int main(){
    int n = 4,m = 4;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int ans = maxArea(arr,n,m);
    cout<<ans;
}