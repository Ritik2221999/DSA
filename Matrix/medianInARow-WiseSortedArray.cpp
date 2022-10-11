#include<bits/stdc++.h>
using namespace std;

// Time Complexity -> O(r*c*log(r*c)
int median(vector<vector<int> > matrix, int r, int c) {
    vector<int> ans(r*c);
    int middleElement = (1+r*c)/2 - 1;
    
    int index = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            ans[index++] = matrix[i][j];
        }
    }
    sort(ans.begin(), ans.end());

    return ans[middleElement];
    
}

int main() {
    vector<vector<int> > matrix {
      {1, 3, 5},
      {2, 6, 9},
      {3, 6, 9}
    };
    
    int result = median(matrix, 3, 3);
    
    cout<<"median is: "<<result<<endl;
   
    return 0;
}




// Time Complexity -> O(log(row*col)
#include<bits/stdc++.h>
using namespace std;

int countSmallerThanEqualToMid(vector<int> &row, int mid) {
    int low = 0, high = row.size()-1;
    
    while(low <= high) {
        int md = (low + high) >> 1;
        
        // mid
        if(row[md] <= mid)
            low = md+1;
        else
            high = md-1;
    }
    return low;
}

int findMedian(vector<vector<int> > &A) {
    // search space
    int low = 1;
    int high = 1e9;
    
    int n = A.size();
    int m = A[0].size();
    
    while(low <= high) {
        int mid = (low+high) >> 1;
        int cnt = 0; // <= mid
        // for every row
        for(int i=0; i<n; i++) {
            cnt += countSmallerThanEqualToMid(A[i], mid);
        }
        
        if(cnt <= (n*m)/2) low = mid+1;
        else high = mid-1;
    }
    return low;
}

int main() {
    int row = 3, col = 3;
    vector<vector<int> > arr = {
        {1, 3, 8},
        {2, 3, 4},
        {1, 2, 5}
    };
    
    cout<<"The median of row-wise sorted matrix is: "<<findMedian(arr)<<endl;
    return 0;
}