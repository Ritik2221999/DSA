#include<bits/stdc++.h>
using namespace std;

class twoStack {
    public:
        int* arr;
        int size;
        int top1;
        int top2;
        
        twoStack(int size) {
            this -> size = size;
            top1 = -1;
            top2 = size;
            arr = new int[size];
        }
        
        // push in Stack - 1
        void push1(int num) {
            if(top2 - top1 > 1) { // at least one space is present
                top1++;
                arr[top1] = num;
            }
            else {
                cout<<"Stack overflow in Stack 1: "<<endl;
            }
        }
        
        // push in Stack - 2 
        void push2(int num) {
            if(top2 - top1 > 1) {
                top2--;
                arr[top2] = num;
            }
            else {
                cout<<"Stack overflow in Stack 2: "<<endl;
            }
        }
        
        int pop1() {
            if(top1 > -1) {
                int ans = arr[top1];
                top1--;
                return ans;
            }
            else {
                cout<<"Stack underflow in Stack 1: "<<endl;
                return -1;
            }
        }
        
        int pop2() {
            if(top2 < size) {
                int ans = arr[top2];
                top2++;
                return ans;
            }
            else {
                cout<<"Stack underflow in Stack 2: "<<endl;
                return -1;
            }
        }
};

int main() {
    
    twoStack ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    
    cout<<"popped element from stack 1 is: "<<ts.pop1()<<endl;;
    
    ts.push2(20);
    
    cout<<"popped element from stack 2 is: "<<ts.pop2()<<endl;
    
    return 0;
}