// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
int find_no_of_zeroes_oficial(int x) {
    // x/5 + x/25 + x/125 + ...
    int denom = 5;
    int zeroes = 0;
    
    while(x >= denom) {
        zeroes += (x/denom);
        denom *= 5;
    }
    return zeroes;
}

public:
    int findNum(int n)
    {
    //complete the function here
    int low = 0;
    int high = n * 5;
    int ans = low;
    
    while(low <= high) {
        int mid = (low + high)/2;
        int zeroes = find_no_of_zeroes_oficial(mid);
        
        if(zeroes >= n) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}
};

int main() {
int t;
cin >> t;
while(t--){
    int n;
    cin >> n;
    Solution ob;
    cout <<ob.findNum(n) << endl;
}
return 0;
}