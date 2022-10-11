#include<bits/stdc++.h>
using namespace std;


// Approach -> 1
// Time Complexity -> O(n)
int power(int x, int n) {
    // base case
    if(n == 0)
        return 1;
    int partialAns = power(x, n-1);
    return x * partialAns;
}

// Approach -> 2 
// Time Complexity -> O(logn)
int power1(int x, int n) {
    // base case
    if(n == 0) return 1;
    int temp = power(x, n/2);
    if(n % 2 == 1) return temp * temp * x;
    return temp * temp;
}

int main() {
    int x, n;
    cout<<"Enter the value is x: "<<endl;
    cin>>x;
    
    cout<<"Enter the nth power: "<<endl;
    cin>>n;
    
    cout<<"The Nth power of number is: "<<endl;
    cout<<power(x, n)<<endl;
    cout<<power1(x, n)<<endl;
    
    return 0;
}