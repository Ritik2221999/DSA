// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
#include<bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n) {
    // create min-heap
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    
    for(int i=0; i<n; i++) {
        pq.push(arr[i]);
    }
    
    long long cost = 0;
    
    while(pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        
        long long b = pq.top();
        pq.pop();
        
        long long sum = a + b;
        cost += sum;
        
        pq.push(sum);
    }
    return cost;
}

int main() {
    long long n;
    cout<<"Enter number of elements in array: "<<endl;
    cin>>n;
    
    long long i, arr[n];
    cout<<"Enter the elements in array: "<<endl;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    cout<<"The Minimum cost of ropes is: "<<endl;
    cout<<minCost(arr, n)<<endl;
}