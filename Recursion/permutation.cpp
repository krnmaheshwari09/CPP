#include<iostream>
#include<string>
#include<vector>
using namespace std;
void solve(string str,vector<string>& ans, int index){
    if(index >= str.length()){
        ans.push_back(str);
        return ;
    }
    for(int i = index;i<str.length();i++){
        swap(str[index],str[i]);
        solve(str,ans,index+1);
        // bapas same laane ke liye
        swap(str[index],str[i]);
    }
}
void permutation(string str,vector<string>& ans){
    int index = 0;
    solve(str,ans,index);
}
int main()
{
    string str;
    cin>>str;
    vector<string> ans;
    permutation(str,ans);
    for(const auto& i:ans){
        cout<<"\""<<i<<"\"\t";
    }
}