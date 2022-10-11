#include<bits/stdc++.h>
using namespace std;

// Time Complexity -> O(logn)
int firstOcc(vector<int> &num, int n, int key) {
    int start = 0, end = n-1;
    int mid = start + (end-start)/2;
    int answer = -1;

    while(start<=end) {
        if (num[mid] == key) {
            answer = mid;
            end = mid-1;  // this is done to find the leftmost occurence!!
        } else if (key>num[mid]) { // go to right
            start = mid+1;

        } else if (key<num[mid]) { // go to left
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return answer;
}
    
int lastOcc(vector<int> &num,int n, int key) {
    int start = 0, end = n-1;
    int mid = start + (end-start)/2;
    int answer = -1;
    
    while(start<=end) {
        if (num[mid] == key) {
            answer = mid;
            start = mid+1;  // this is done to find the rightmost occurence!!
        } else if (key>num[mid]) { // go to right
            start = mid+1;
            
        } else if (key<num[mid]) { // go to left
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return answer;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    int n = nums.size();
    int first = firstOcc(nums, n, target);
    int last = lastOcc(nums, n, target);

    ans.push_back(first);
    ans.push_back(last);

    return ans;
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    
    vector<int> result = searchRange(nums, target);
    cout<<"the starting and ending position of:"<<target<<" is: "<<endl;
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }cout<<endl;
    return 0;
}




// Naive Approach
#include<bits/stdc++.h>
using namespace std;

// Tine Complexity -> O(n)
vector<int> firstAndLastOcc(vector<int> &arr, int n, int x) {
    int first = -1;
    int last = -1;
    vector<int> ans;
    
    for(int i=0; i<n; i++) {
        if(arr[i] == x && first == -1)
            first = i;
        if(arr[i] == x && first != -1)
            last = i;
    }
    if(first != -1) {
        ans.push_back(first);
        ans.push_back(last);
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125}; 
    int n = arr.size();
    
    int target = 5;
    vector<int> ans = firstAndLastOcc(arr, n, target);
    
    cout<<"first and last occurrence of: "<<target<<" is: "<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}