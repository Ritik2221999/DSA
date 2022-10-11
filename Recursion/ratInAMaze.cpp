#include<bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool> > &vis, vector<vector<int> > &arr, int n) {
    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) &&
        (vis[newx][newy] != 1 && arr[newx][newy] == 1)) {
        return true;
    }
    else
        return false;
}

void solve(int x, int y, vector<vector<int> > &arr, int n, vector<string> &ans, vector<vector<bool> > &vis,
string path) {
    // base case
    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return ;
    }
    
    // 4 -> movements = D, L, R, U 
    vis[x][y] = 1;
    
    // Down
    if(isSafe(x+1, y, vis, arr, n)) {
        solve(x+1, y, arr, n, ans, vis, path + 'D');
    }
    
    // Left
    if(isSafe(x, y-1, vis, arr, n)) {
        solve(x, y-1, arr, n, ans, vis, path + 'L');
    }
    
    // Right
    if(isSafe(x, y+1, vis, arr, n)) {
        solve(x, y+1, arr, n, ans, vis, path + 'R');
    }
    
    // Up
    if(isSafe(x-1, y, vis, arr, n)) {
        solve(x-1, y, arr, n, ans, vis, path + 'U');
    }
    vis[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int> > &arr, int n) {
    vector<string> ans;
    string path = "";
    vector<vector<bool> > visited(n, vector<bool> (n, 0));
    if(arr[0][0] == 0)
        return ans;
        
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}

int main() {
    vector<vector<int >> arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}  
    };
    int n = 4;
    cout<<"The possible paths that the rat can take to reach from source to destination in the maze: "<<endl;
    vector<string> ans = searchMaze(arr, n);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}