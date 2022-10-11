// https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1
#include<bits/stdc++.h>
using namespace std;

vector<string> winner(string arr[], int n) {
    unordered_map<string, int> mp;
    
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }
    
    string name=" ";
    int maxVote = 0;
    for(auto it=mp.begin(); it != mp.end(); it++) {
        string key = it -> first;
        int val = it -> second;
        
        if(val > maxVote) {
            maxVote = val;
            name = key;
        }
        else if(val == maxVote) {
            if(key < name)
                name = key;
        }
    }
    vector<string> ans;
    ans.push_back(name);
    string temp = to_string(maxVote);
    ans.push_back(temp);
    
    return ans;
}

int main() {
    string votes[] = {"john", "johnny", "jackie", "johnny","john", 
    "jackie", "jamie", "jamie", "john", "johnny", "jamie", "johnny", "john"};
    
    int n = sizeof(votes)/sizeof(votes[0]);
    cout<<"Candidate that received maximum votes: "<<endl;
    vector<string> result = winner(votes, n);
    cout<<result[0]<<" "<<result[1] <<endl;
    return 0;
}