#include<bits/stdc++.h>
using namespace std;

// Time Complexity -> O(2^n)
void powerSet(vector<int> &v, int currElement, vector<int> &subSet, vector<vector<int> > &ans) {
//       base case
    if(currElement == v.size()) {
        ans.push_back(subSet);
        return ;
    }
    
//     include the curr element in subset
    subSet.push_back(v[currElement]);
    powerSet(v, currElement+1, subSet, ans);
    
//     to ignore the element and not include in the subset, but we already included it so pop() it
    subSet.pop_back();

    // skip the particular element
    powerSet(v, currElement+1, subSet, ans);
}

vector<vector<int> > pwset(vector<int> &v) {
    vector<vector<int> > ans;
    vector<int> subSet;
    powerSet(v, 0, subSet, ans);
    return ans;
}

int main() {
    vector<int> v = {1, 2, 3};
    
    vector<vector<int> > result;
    result = pwset(v);
    
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}








// Approach -> 2 -> Bit manipulation

#include<bits/stdc++.h>
#include<vector>
using namespace std;

// Time Complexity -> O(n*(2^n)
vector<vector<int> > powerSet(vector<int> &arr) {
    int n = pow(2, arr.size());
    
    vector<vector<int> > ans;
    
    for(int i=1; i<n; i++) {
        vector<int> temp;
        int curr = i; // store the bits from 1 to n like, 1, 11, 111, 01, 001 etc.
        int elemIterate = 0;
        
        while(curr) {
            if(curr&1) // if set bit is present i.e. '1'
                temp.push_back(arr[elemIterate]);
            elemIterate++;
            // right shift the bit
            curr = curr >> 1;
        }
        ans.push_back(temp);
    }
    // sort(ans.begin(), ans.end());
    return ans;
}


int main()
{
    // Taking user input.
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++)
       cin >> arr[i];

    // Calling powerSet() function to generate the power set of 'ARR'.
    vector<vector<int>> ans = powerSet(arr);

    // Printing the power set.
    cout<<"printing all subsequences: "<<endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}