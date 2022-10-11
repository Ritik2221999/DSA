// https://www.codingninjas.com/codestudio/problems/letter-combinations-of-a-phone-number_983623

#include<bits/stdc++.h>
using namespace std;

void helper(int i, string &s, string &temp, vector<string> &ans, unordered_map<char,string> &m) {
//     base case
    if(i == s.size()) {
        ans.push_back(temp);
        return ;
    }
    string str = m[s[i]];
    for(int j=0; j<str.size(); j++) {
        temp.push_back(str[j]);
        helper(i+1, s, temp, ans, m);
        temp.pop_back();
    }
}

vector<string> combinations(string s){
	
	// Write your code here
	unordered_map<char,string> m;
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
 
    string temp;
    vector<string> ans;
    
    helper(0, s, temp, ans, m);
    return ans;
}

int main() {
    string str;
    cout<<"Enter the digits from 2 to 9 inclusive: "<<endl;
    cin>>str;
    
    vector<string> result = combinations(str);
    cout<<"all possible letter combinations that the number could represent: "<<endl;
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }cout<<endl;
    
    return 0;
}