// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1
#include<bits/stdc++.h>
using namespace std;

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
    // Code here
    int x1 = KnightPos[0];
    int y1 = KnightPos[1];
    
    int x2 = TargetPos[0];
    int y2 = TargetPos[1];
    
    int a[1001][1001];
    
   // if at starting the index match return 0
    if(x1 == x2 && y1 == y2)
        return 0;
   
   //mark all matrix indexes to zero at starting
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            a[i][j] = 0;
        }
    }
    int n = N;
    
    queue<pair<int, int> > q;
    q.push(make_pair(x1-1, y1-1)); // given 1-based indexing so converting to zero based
                                   // by decrementing -1 to each index	    
    while(!q.empty()) {
        auto curr = q.front();
        int i = curr.first;
        int j = curr.second;
        q.pop();
        
        if((i+1) >= 0 && (i+1) < n && (j+2) >=0 && (j+2) < n && a[i+1][j+2] == 0) {
            a[i+1][j+2] = a[i][j] + 1; // at every index store the current index element adding '1' to the next index
            q.push(make_pair(i+1, j+2));
        }
        if((i-1) >= 0 && (i-1) < n && (j+2) >=0 && (j+2) < n && a[i-1][j+2] == 0) {
            a[i-1][j+2] = a[i][j] + 1;
            q.push(make_pair(i-1, j+2));
        }
        if((i-2) >= 0 && (i-2) < n && (j+1) >=0 && (j+1) < n && a[i-2][j+1] == 0) {
            a[i-2][j+1] = a[i][j] + 1;
            q.push(make_pair(i-2, j+1));
        }
        if((i+2) >= 0 && (i+2) < n && (j+1) >=0 && (j+1) < n && a[i+2][j+1] == 0) {
            a[i+2][j+1] = a[i][j] + 1;
            q.push(make_pair(i+2, j+1));
        }
        if((i-1) >= 0 && (i-1) < n && (j-2) >=0 && (j-2) < n && a[i-1][j-2] == 0) {
            a[i-1][j-2] = a[i][j] + 1;
            q.push(make_pair(i-1, j-2));
        }
        if((i+1) >= 0 && (i+1) < n && (j-2) >=0 && (j-2) < n && a[i+1][j-2] == 0) {
            a[i+1][j-2] = a[i][j] + 1;
            q.push(make_pair(i+1, j-2));
        }
        if((i-2) >= 0 && (i-2) < n && (j-1) >=0 && (j-1) < n && a[i-2][j-1] == 0) {
            a[i-2][j-1] = a[i][j] + 1;
            q.push(make_pair(i-2, j-1));
        }
        if((i+2) >= 0 && (i+2) < n && (j-1) >=0 && (j-1) < n && a[i+2][j-1] == 0) {
            a[i+2][j-1] = a[i][j] + 1;
            q.push(make_pair(i+2, j-1));
        }
    }
    return a[x2-1][y2-1]; // return the last index
}

int main(){
	
	vector<int>KnightPos(2);
	vector<int>TargetPos(2);
	
	int N;
	cout<<"Enter the size of matrix: "<<endl;
	cin >> N;
	
	cout<<"Enter the position of kinght in chess board: "<<endl;
	cin >> KnightPos[0] >> KnightPos[1];
	cout<<"Enter the position of target in chess board: "<<endl;
	cin >> TargetPos[0] >> TargetPos[1];
	
	int ans = minStepToReachTarget(KnightPos, TargetPos, N);
	cout<<"The minimum steps knight takes to reach target is: "<<endl;
	cout << ans <<"\n";
	
	return 0;
}