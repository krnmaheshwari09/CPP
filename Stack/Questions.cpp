#include<iostream>
#include<stack>
using namespace std;

// reverse of a string
/*int main()
{
    string str = "Karan";
    stack<char> s;
    for(int i = 0;i<str.length();i++){
        s.push(str[i]);
    }
    string ans = "";
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    cout<<"Answer is : "<<ans<<endl;
}*/


// to delete middle element of a stack
/*void solve(stack<int>&inputStack, int size, int count = 0){
    // base case
    if(count == size/2){
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();
    // recusrsive call
    solve(inputStack,size,count+1);
    inputStack.push(num);
}
int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    solve(s,s.size());
    int length = s.size();
    for(int i = 0;i<length;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
}*/


// Valid parathesis
/*bool valid(string expression){
    stack<char>s;
    for(int i = 0;i<expression.length();i++){
        char ch = expression[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }else{
            if(!s.empty()){
                char top = s.top();
                if((ch == ')' && top == '(')||(ch == ']' && top == '[')||(ch = '}' && top == '{')){
                    s.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }else{
        return false;
    }
}
int main(){
    string str = "[]{}()";
    if(valid(str)){
        cout<<"Balanced";
    }else{
        cout<<"Not Balanced";
    }
}*/


// insert top element at bottom
/*void solve(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        return ;
    }
    int num = s.top();
    s.pop();
    solve(s, x);
    s.push(num);
}
int main(){
    int x = 9;
    stack<int> arr;
    arr.push(7);
    arr.push(1);
    arr.push(4);
    arr.push(5);
    solve(arr,x);
    int len = arr.size();
    for(int i = 0;i<len;i++){
        cout<<arr.top()<<" ";
        arr.pop();
    }
}*/


// reverse stack using recusion
/*void solve(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        return ;
    }
    int num = s.top();
    s.pop();
    solve(s, x);
    s.push(num);
}
void reverse(stack<int>& s){
    if(s.empty()){
        return ;
    }
    int num = s.top();
    s.pop();
    reverse(s);
    solve(s,num);
}
int main(){
    stack<int> arr;
    arr.push(7);
    arr.push(1);
    arr.push(4);
    arr.push(5);
    reverse(arr);
    int len = arr.size();
    for(int i = 0;i<len;i++){
        cout<<arr.top()<<" ";
        arr.pop();
    }
}*/


// sort stack
/*void solve(stack<int>& s,int num){
    if(s.empty()){
        s.push(num);
        return ;
    }
    int x = s.top();
    if(num<x){
        s.pop();
        solve(s,num);
        s.push(x);
    }else{
        s.push(num);
    }
}
void sort(stack<int>& s){
    if(s.empty()){
        return ;
    }
    int num = s.top();
    s.pop();
    sort(s);
    solve(s,num);
}
int main(){
    stack<int> arr;
    arr.push(7);
    arr.push(1);
    arr.push(4);
    arr.push(5);
    sort(arr);
    int len = arr.size();
    for(int i = 0;i<len;i++){
        cout<<arr.top()<<" ";
        arr.pop();
    }
}*/


// reduntant brackets
/*bool find(string &s){
    stack<char> st;
    for(int i = 0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }else{
            if(ch == ')'){
                bool isReduntant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isReduntant = false;
                    }
                    st.pop();
                }
                if(isReduntant){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}*/


// minimum cost to make string valid
int calculate(string str){
    if(str.length()%2 != 0){
        return -1;
    }
    stack<char> s;
    for(int i = 0;i<str.length();i++){
        char ch = str[i];
        if(ch == '{'){
            s.push(ch);
        }else{
            if(!s.empty() && s.top() == '{'){
                s.pop();
            }else{
                s.push(ch);
            }
        }
    }
    int a = 0, b = 0;
    while(!s.empty()){
        if(s.top() == '{'){
            b++;
        }else{
            a++;
        }
        s.pop();
    }
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}