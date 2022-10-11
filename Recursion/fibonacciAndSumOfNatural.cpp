#include<bits/stdc++.h>
using namespace std;

int sum(int n) {
    // base case
    if(n == 1) return 1;
    int partialAns = sum(n-1);
    return n + partialAns;
}

int fibo(int n) {
    // base cases
    if(n == 1) return 1;
    if(n == 2) return 1;
    int partialAns1 = fibo(n-1);
    int partialAns2 = fibo(n-2);
    return partialAns1 + partialAns2;
}


int main() {
    int n;
    cin>>n; 
    cout<<"sum of "<<n<<" natural number is: "<<endl;
    cout<<sum(n)<<endl;
    cout<<"fibonacci of "<<n <<" number is: "<<endl;
    cout<<fibo(n);
}

