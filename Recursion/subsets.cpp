#include<iostream>
#include<vector>
using namespace std;
// void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>>& ans){
//     // base case
//     if(index >= nums.size()){
//         ans.push_back(output);
//         return ;
//     }
//     // exclude
//     solve(nums,output,index+1,ans);
//     // include
//     int element = nums[index];
//     output.push_back(element);
//     solve(nums,output,index+1,ans);
// }
// void subsets(vector<int>& nums,vector<vector<int>>& ans){
//     vector<int> output;
//     int index = 0;
//     solve(nums,output,index,ans);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> arr;
//     for(int i=0;i<n;i++){
//         int t;
//         cin>>t;
//         arr.push_back(t);
//     }
//     vector<vector<int>> ans;
//     subsets(arr,ans);
//     for(const auto& i:ans){
//         cout<<"[";
//         for(const auto& j:i){
//             cout<<j<<" ";
//         }
//         cout<<"]\t";
//     }
// }
void solve(string str,string output,int index,vector<string>& ans){
    // base case
    if(index >= str.length()){
        ans.push_back(output);
        return ;
    }
    // exclude
    solve(str,output,index+1,ans);
    // include
    char element = str[index];
    output.push_back(element);
    solve(str,output,index+1,ans);
}
void subsets(string str,vector<string>& ans){
    string output;
    int index = 0;
    solve(str,output,index,ans);
}
int main()
{
    string arr;
    cin>>arr;
    vector<string> ans;
    subsets(arr,ans);
    for(const auto& i:ans){
        cout<<"["<<i<<"]\t";
    }
}