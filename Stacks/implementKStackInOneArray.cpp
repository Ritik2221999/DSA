// https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271

#include<bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;
    
    int n, s;
    int freespot;
    
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
//         top initialize
        for(int i=0; i<n; i++) {
            top[i] = -1;
        }
        
//         next initialize
        for(int i=0; i<s; i++) {
            next[i] = i+1;
        }
//         update last index to -1
        next[s-1] = -1;
        
//         initialize freespot
        freespot = 0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for oveflow
        if(freespot == -1)
            return false;
        
//         step: 1) find index
        int index = freespot;
        
//         step: 2) update freespot
        freespot = next[index];
        
//         step: 3) insert element in array
        arr[index] = x;
        
//         step: 4) update next
        next[index] = top[m-1];
        
//         step: 5) update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow condition
        if(top[m-1] == -1)
            return -1;
        
        int index = top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;
        
        return arr[index];
    }
};


int main() {
    
    NStack k1(4, 2);
    
    k1.push(1, 1);
    k1.push(2, 1);
    k1.push(3, 1);

    // Adding elements to stack 2
    k1.push(4, 2);
    k1.push(5, 2);
    k1.push(6, 2);

    // Removing elements from Stack 1
    cout<<k1.pop(1)<<endl;
    cout<<k1.pop(1)<<endl;
    cout<<k1.pop(1)<<endl;

    // Removing elements from Stack 2
    cout<<k1.pop(2)<<endl;
    cout<<k1.pop(2)<<endl;
    cout<<k1.pop(2)<<endl;
    
    return 0;
}