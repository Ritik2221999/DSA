// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0
#include<bits/stdc++.h>
using namespace std;

string firstNonRepeating(string A) {
    unordered_map<char, int> count;
    queue<int>q;
    string ans = "";
    
    for(int i=0; i<A.length(); i++) {
        char ch = A[i];
        
        // increment count
        count[ch]++;
        
        // push into queue
        q.push(ch);
        
        while(!q.empty()) {
            if(count[q.front()] > 1) {
                // repeating character
                q.pop();
            }
            else {
                // non repeating character
                ans.push_back(q.front());
                break;
            }
        }
        
        if(q.empty()) {
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
	string A = "aabc";
	string ans = firstNonRepeating(A);
	cout << ans << "\n";
	
	return 0;
}