// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
    
        unordered_map<string, vector<string> > umap;
        
        for(auto x: string_list) {
            string temp = x;
            sort(x.begin(), x.end());
            umap[x].push_back(temp);  //umap[x]->contains sorted key and this key will have anagrams treated as values
        }
        
        for(auto x: umap) {
            vector<string> temp = x.second; // x.second contains values and x.first contains key(sorted)
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    vector<string> string_list = {"eat","tea","tan","ate","nat","bat"};
    Solution ob;
    vector<vector<string> > result = ob.Anagrams(string_list);
    cout<<"[";
    for (int i = 0; i < result.size(); i++)
    {
        cout<<"[";
        for(int j=0; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<",";
        }
        cout<<"]";
    }
    cout<<"]";

    return 0;
}
  // } Driver Code Ends