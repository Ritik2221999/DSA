#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int> > st;
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
   
   for(int i=0; i<n; i++) {
       for(int j=i+1; j<n; j++) {
           int low = j+1;
           int high = n-1;
           
           while(low < high) {
               long long int sum = (long long int)nums[i] + nums[j] + nums[low] + nums[high];
               
                if(sum > target)
                    high--;
                else if(sum < target)
                    low++;
                else {
                    st.insert({nums[i], nums[j], nums[low], nums[high]});
                    low++;
                    high--;
                }
           }
       }
   }
   
   vector<vector<int>> result(st.begin(), st.end());
   return result;
}

int main() {
    vector<int> arr = {0,0,2,1,1};
    int k = 3; // quadruple sum required
    vector<vector<int> > result = fourSum(arr, k);
    
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }
    }cout<<endl;
    
    return 0;
}