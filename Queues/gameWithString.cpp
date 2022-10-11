// https://practice.geeksforgeeks.org/problems/game-with-string4100/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char, int> m;
        
        for(int i=0; i<s.length(); i++) {
            m[s[i]]++;
        }
        
        priority_queue<int> pq;
        for(auto x: m) {
            pq.push(x.second);
        }
        
        while(k != 0) {
            int x = pq.top();
            pq.pop();
            x--;
            pq.push(x);
            k--;
        }
        
        int sum = 0;
        while(!pq.empty()) {
            int d = pq.top();
            sum += d*d;
            pq.pop();
        }
        return sum;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}