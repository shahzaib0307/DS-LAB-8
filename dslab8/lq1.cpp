// Task 1: Implement and insert the values “BORROWROB” in the stack and identify if it’s a palindrome
// or not. Use the push and pop functions to accomplish this (Note: Use Arrays to accomplish this)

#include <iostream>
using namespace std; 

void push(char *arr, char val, int top){
    arr[top] = val; 
    // cout<<arr[top]<<endl;
}

char pop(char *arr, int top){
    // cout<<arr[top]<<endl; 
    return arr[top]; 
}

int main(){
    string a  = "BORROWROB"; 
    int n = a.size();
    char *sahi = new char[n]; 
    char *ulta = new char[n]; 
    int top = 0;  
    while(top<n){
        push(sahi, a[top], top);
        push(ulta, a[n-top-1], top); 
        top++; 
    }
    bool flg = true; 
    while(top>0 && flg){
        if(pop(sahi, top)!=pop(ulta, top)) flg = false; 
        top--; 
    }
    if(flg) cout<<"PALINDROME"<<endl; 
    else cout<<"NOT A PALINDROME"; 
}
