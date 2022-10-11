#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
    vector<int> ans;
    
    int row = r;
    int col = c;
    
    int count = 0;
    int total = row*col;
    
    // index initilaization
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;
    
    while(count < total) {
        // print starting row -> top row
        for(int index = startingCol; count < total && index <= endingCol; index++) {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++; // move to inner square
        
        // for ending col -> right side col
        for(int index = startingRow; count < total && index <= endingRow; index++) {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;
        
        // for bottom row -> left to right
        for(int index = endingCol; count < total && index >= startingCol; index--) {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;
        
        // for starting col -> bottom to top
        for(int index = endingRow; count < total && index >= startingRow; index--) {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main() {
    
    vector<vector<int> > matrix {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15,16}
    };
           
    vector<int> result;
           
    result = spirallyTraverse(matrix, 4, 4);
    
    cout<<"Spirally tarversing of matrix is: "<<endl;
    for(int i=0; i<4*4; i++) {
        cout<<result[i]<<" ";
    }cout<<endl;
    
    return 0;
}