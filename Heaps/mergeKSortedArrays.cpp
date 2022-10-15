// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        int i;
        int j;
        
        node(int data, int row, int col) {
            this -> data = data;
            this -> i = row;
            this -> j = col;
        }
};

class compare {
    public:
        bool operator()(node* a, node* b) {
            return a -> data > b -> data;
        }
};


vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    //code here
    priority_queue<node*, vector<node*>, compare> minHeap;
    
    // step: 1) Insert first elements of every array in minHeap
    for(int i=0; i<K; i++) {
        node* temp = new node(arr[i][0], i, 0);
        minHeap.push(temp);
    }
    
    // step: 2) find top element from minheap and push into ans array
    vector<int> ans;
    
    while(minHeap.size() > 0) {
        node* temp = minHeap.top();
        ans.push_back(temp -> data);
        minHeap.pop();
        
        // store the current indexes to check if they are out of range or not
        int i = temp -> i;
        int j = temp -> j;
        
        // if current element not out of range in current row and present in current array, push into minHeap
        if(j + 1 < arr[i].size()) {
            node* next = new node(arr[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }
    return ans;
}

void printArray(vector<int> arr, int k) {
    for(int i=0; i<k; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main() {
    int k;
    cout<<"Enter the size of matrix: "<<endl;
    cin>>k;
    
    vector<vector<int> > arr(k, vector<int> (k, 0));
    
    
    for(int i=0; i<k; i++) {
        cout<<"Enter elements in: "<<i<<" row: "<<endl;
        for(int j=0; j<k; j++) {
            cin>>arr[i][j];
        }
    }
    
    cout<<"After merging: "<<k<<" sorted arrays is: "<<endl;
    vector<int> output = mergeKArrays(arr, k);
    printArray(output, k * k);
    
    return 0;
}