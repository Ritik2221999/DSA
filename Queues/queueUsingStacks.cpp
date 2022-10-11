// https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1
#include<bits/stdc++.h>

using namespace std;

class StackQueue{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        void push(int B);
        int pop();

};

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }


}

void StackQueue :: push(int x)
{
    // push s1 to s2 stack
    while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    
    // push element to stack
    s1.push(x);
    
    // push everything back to s1
    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
        // Your Code      
        if(s1.empty())
            return -1;
            
        int data = s1.top();
        s1.pop();
        return data;
}