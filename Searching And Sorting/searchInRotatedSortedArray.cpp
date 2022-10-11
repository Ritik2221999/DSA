#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>& arr, int n) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e) {
        if (arr[mid] >= arr[0]) {
            s = mid+1;
        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key) {
    int start = s;
    int end = e;

    // int mid = (start + end)/2;
    // optimised formula
    int mid = start +  (end - start)/2;

    while(start <= end) {
        if (arr[mid] == key) {
            return mid;
        }

        if (key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid-1;
        }
        // mid = (start+end)/2;
        mid = start +  (end-start)/2;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int pivot = getPivot(nums, n);
    
    if(target >= nums[pivot] && target <= nums[n-1]) // binary search for right part
        return binarySearch(nums, pivot, n-1, target);
    else
        return binarySearch(nums, 0, pivot-1, target);
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout<<"The index is: "<<endl;
    cout<<search(nums, target);
    return 0;
}