#include<iostream>
#include<stack>
using namespace std;

class Nstack {
    int *arr;
    int *top;
    int *next;
    int n,s, freespot;

    public:
    Nstack(int n,int s){
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        // top initialise
        for(int i = 0;i<n;i++){
            top[i] = -1;
        }
        // next initialsie
        for(int i = 0;i<s;i++){
            next[i] = i+1;
        }
        // update last index value to -1
        next[s-1] = -1;
        // Initialise freespot
        freespot = 0;
    }
    bool push(int x, int m){
        // check overflow
        if(freespot == -1){
            return false;
        }
        // find index
        int index = freespot;
        // update freespot
        freespot = next[index];
        // insert element into array
        arr[index] = x;
        // update next
        next[index] = top[m-1];
        // update top
        top[m-1] = index;
        return true;
    }
    int pop(int m){
        // check underflow
        if(top[m-1] == -1){
            return -1;
        }
        // reverse of push function
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};