#include<iostream>
#include<string>
#include<vector>
using namespace std;
void solve(string digits,string output,int index,vector<string>& ans,string mapping[]){
    // base case
    if(index >= digits.length()){
        ans.push_back(output);
        return ;
    }
    int number = digits[index] - '0';
    string value = mapping[number];
    for(int i = 0;i<value.length();i++){
        output.push_back(value[i]);
        solve(digits,output,index+1,ans,mapping);
        output.pop_back();
    }
}
void letter(string digits,vector<string>& ans){
    if(digits.length()==0){
        return ; 
    }
    string output;
    int index = 0;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,output,index,ans,mapping);
}
int main()
{
    string str;
    cin>>str;
    vector<string> ans;
    letter(str,ans);
    for(const auto& i:ans){
        cout<<"\""<<i<<"\"\t";
    }
}