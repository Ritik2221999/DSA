#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    
    int n = intervals.size();
    vector<vector<int>> ans;
    
    for(int i=0; i<n; i++) {
        if(ans.empty()) {
            ans.push_back(intervals[i]);
        } else {
            vector<int> &v = ans.back();
            int previous = v[1];
            
            if(intervals[i][0] <= previous) {
                v[1] = max(previous, intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
    }
    return ans;

}

int main() {
    vector<vector<int>> intervals = { {1,3}, {2,6}, {8,10}, {15,18} };
    vector<vector<int>> ans;
    ans = merge(intervals);
   
    cout<<"merged array is: "<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<< "[" <<ans[i][0]<<","<<ans[i][1]<< "]";
    }
    
    return 0;
}
