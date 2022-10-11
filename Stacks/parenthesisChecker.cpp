// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
         stack<char> s;
    
    for(int i=0; i<x.length(); i++) {
        char ch = x[i];
    
        // if opening bracket push to stack
        // if closing bracket, and closing and opening same pop from stack
        
        // for opening brackets
        if(ch == '[' || ch == '(' || ch == '{') {
            s.push(ch);
        }
        else {
            // for closing brackets
            if(!s.empty()) {
                char top = s.top();
                
                if((ch == ']' && top == '[') ||
                   (ch == '}' && top == '{') ||
                   (ch == ')' && top == '(')) {
                       s.pop();
                }
                else {
                   return false;
                }
            }
            else 
                return false;
        }
       
    }
     if(s.empty())
        return true;
    else
        return false;
    }

};

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}