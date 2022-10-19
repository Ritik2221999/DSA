#include<bits/stdc++.h>
using namespace std;

// Naive Approach
// Time Complexity -> O(n^2)
void insertionSort(vector<int> &nums) {
    int lastElement = nums.size()-1;
    
    while(lastElement > 0 && nums[lastElement] < nums[lastElement - 1]) {
        swap(nums[lastElement - 1], nums[lastElement]);
        lastElement--;
    }
}

void medianStream(vector<int> nums) {
    vector<int> sortedElements;
    
    for(int i=0; i<nums.size(); i++) {
        sortedElements.push_back(nums[i]);
        
        if(sortedElements.size() == 1) {
            cout<<sortedElements[0]<<" ";
        }
        else {
            insertionSort(sortedElements);
            
            if(sortedElements.size() % 2 == 1) {
                int mid = sortedElements.size()/2;
                cout<<sortedElements[mid]<<" ";
            }
            else {
                int mid1 = (sortedElements.size() - 1)/2;
                int mid2 = sortedElements.size()/2;
                
                cout<<(float)(sortedElements[mid1] + sortedElements[mid2])/2<<" ";
            }
        }
    }
}


// Approach - 2 
// Time Complexity -> O(n*logn)
int signum(int a, int b) {
    if(a == b) return 0; // a -> maxHeap && b -> minHeap
    else if (a > b) return 1;
    else return -1;
}

void callMedian(int element, priority_queue<int> &maxi, 
 priority_queue<int, vector<int>, greater<int>> &mini, int &median) {
    
    switch(signum(maxi.size(), mini.size())) {
        
        case 0: if(element > median) {
            mini.push(element);
            median = mini.top();
        }
        else {
            maxi.push(element);
            median = maxi.top();
        }
        break;
        
        case 1: if(element > median) {
            mini.push(element);
            median = (mini.top() + maxi.top())/2;
        }
        else {
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(element);
            median = (mini.top() + maxi.top())/2;
        }
        break;
        
        case -1: if(element > median) {
            maxi.push(mini.top());
            mini.pop();
            mini.push(element);
            median = (mini.top() + maxi.top())/2;
        }
        else {
            maxi.push(element);
            median = (mini.top() + maxi.top());
        }
        break;
    } 
}

vector<int> findMedian(vector<int> &arr, int n) {
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;
    
    for(int i=0; i<n; i++) {
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

int main() {
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    
    // Approach - 1
    cout<<"Median in stream of running integers are: -> using insertion sort"<<endl;
    medianStream(arr);
    
    // Approach - 2
    
    int n = arr.size();
    
    vector<int> ans = findMedian(arr, n);
    
    cout<<"\nMedian in stream of running integer is: -> using heap data structure"<<endl;
    for(auto i: ans) {
        cout<<i<<" ";
    }cout<<endl;
    
    return 0;
}