#include<bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    map<int, int> mp;
    
    vector<int> ans;
    
    for(auto x: arr1)
        mp[x]++;
    
    for(auto temp: arr2) {
        if(mp.find(temp) != mp.end()) {
            auto x = mp.find(temp);
            int count = x -> second;  // 5 -> 2(no of times repeated)
            vector<int> v(count, temp); // 5 5  -> (count = 2 and temp = 5)
            ans.insert(ans.end(), v.begin(), v.end());
            mp.erase(temp);  // found the element pushed in vector then remove so that it won't repeat
        }
    }
    
    // the elements that are left in map after erasing the matched elements from arr1 and arr2
    for(auto x: mp) {
        int ele = x.first;
        int count = x.second;
        vector<int> v(count, ele);
        ans.insert(ans.end(), v.begin(), v.end());
    }
    return ans;
}

int main() {
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    
    vector<int> result = relativeSortArray(arr1, arr2);
    
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }cout<<endl;
    return 0;
}