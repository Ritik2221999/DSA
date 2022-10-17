// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
#include<bits/stdc++.h>
using namespace std;
#define N 1000

class node {
    public:
        int data;
        int row;
        int col;
        
        node(int d, int r, int c) {
            data = d;
            row = r;
            col = c;
        }
};

class compare {
    public:
        bool operator()(node* a, node* b) {
            return a -> data > b -> data;
        }
};


pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
{
      //code here
      int mini = INT_MAX, maxi = INT_MIN;
      priority_queue<node*, vector<node*>, compare> minHeap;
      
    //   step: 1) create a min heap for starting element of each list and 
    // tracking min/max value
    for(int i=0; i<k; i++) {
        int element = KSortedArray[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }
    
    int start = mini, end = maxi;
    
    // process ranges
    while(!minHeap.empty()) {
        // fetch mini
        node* temp = minHeap.top();
        minHeap.pop();
        
        mini = temp -> data;
        
        // range or answer updation
        if(maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }
        
        // next element exists or not
        if(temp -> col + 1 < n) {
            maxi = max(maxi, KSortedArray[temp -> row][temp -> col + 1]);
            minHeap.push(new node(KSortedArray[temp -> row][temp -> col + 1], 
                            temp -> row, temp -> col + 1));
        }
        else
            break;
    }
    // returning the difference of values of range
    pair<int, int> result = make_pair(start, end);
    return result;
}

int main() {
    int n, k;
    cout<<"Enter number of elments in a list: "<<endl;
    cin>>n;
    cout<<"Enter number of lists: "<<endl;
    cin>>k;
    
    int arr[N][N];
    
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<k; i++) {
        cout<<"Enter elements in: "<<i<<" list with "<<n<<" elements: "<<endl;
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }
    
    pair<int, int> range = findSmallestRange(arr, n, k);
    cout<<"Smallest range in: "<<k<<" lists: "<<endl;
    cout<<"Min -> "<<range.first<<" "<<"Max -> "<<range.second<<endl;
    
    return 0;
}