// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
#include<bits/stdc++.h>
using namespace std;

//Function to find distance of nearest 1 in the grid for each cell.
vector<vector<int>>nearest(vector<vector<int>>grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int> > ans(n, vector<int> (m, INT_MAX));
    queue<pair<int, int> > q;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1) {
                ans[i][j] = 0;
                q.push({i, j}); // store the index of all 1's in queue for traversing
            }
        }
    }
    
    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        
        if((i-1)>=0 && ans[i][j] + 1 < ans[i-1][j]) {
            ans[i-1][j] = ans[i][j] + 1;
            q.push({i-1, j});  // store index in queue for future traversal
        }
        
        if((j-1)>=0 && ans[i][j] + 1 < ans[i][j-1]) {
            ans[i][j-1] = ans[i][j] + 1;
            q.push({i, j-1});
        }
        
        if((i+1)<n && ans[i][j] + 1 < ans[i+1][j]) {
            ans[i+1][j] = ans[i][j] + 1;
            q.push({i+1, j});
        }
        
        if((j+1)<m && ans[i][j] + 1 < ans[i][j+1]) {
            ans[i][j+1] = ans[i][j] + 1;
            q.push({i, j+1});
        }
        q.pop();
    }
    return ans;
}


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		
		cout<<"resultant vector is: "<<endl;
		vector<vector<int>> ans = nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}