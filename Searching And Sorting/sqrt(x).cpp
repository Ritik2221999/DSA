#include<bits/stdc++.h>
using namespace std;

long long int binarySearch(long long int n) {
    int start = 0;
    int end = n;
    
    int mid = start + (end - start)/2;
    long long int answer = -1;
    
    while(start <= end) {
        long long int square = mid * mid;
        
        if(square == n)
            return mid;
        if(square < n) {
            answer = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end -  start)/2;
    }
    return answer;
} 

int mySqrt(int x) {
    return binarySearch(x);
}

int main() {
    int x;
    cout<<"Enter the element: "<<endl;
    cin>>x;
    
    cout<<"The square root of:"<<x<<" is"<<endl;
    cout<<mySqrt(x);
    
    return 0;
}