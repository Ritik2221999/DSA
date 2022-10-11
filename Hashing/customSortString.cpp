// https://leetcode.com/problems/custom-sort-string/

#include<bits/stdc++.h>
using namespace std;

string customSortString(string order, string s) {
    map<char, int> mp;
    string ans = "";
    
    for(auto x: s) 
        mp[x]++;
    for(auto x: order) {
        if(mp.find(x) != mp.end()) {
            auto temp = mp.find(x);
            int count = temp -> second;
            string s(count, x); // c -> 5 / c c c c c
            ans+=s;
            mp.erase(x);
        }
    }
    for(auto x: mp) {
        string s(x.second, x.first); // c->2 / c c
        ans+=s;
    }
    return ans;
}

int main() {
    string order = "cba";
    string s = "abcd";
    
    cout<<"custom sort string is: "<<endl;
    cout<<customSortString(order, s);
    return 0;
}