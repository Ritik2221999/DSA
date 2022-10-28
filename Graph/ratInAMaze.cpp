// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;

vector<string> v;

void dfs(int i, int j, string s, vector<vector<int> > &m, int n, vector<vector<int> > &visited) {
    // base cases
    if(i < 0 || j < 0 || i >= n || j >= n) return ;
    if(m[i][j] == 0 || visited[i][j] == 1) return ;
    
    if(i == n-1 && j == n-1) {
        v.push_back(s);
        return ;
    }
    
    visited[i][j] = 1;
    
    dfs(i-1, j, s + 'U', m, n, visited);
    dfs(i+1, j, s + 'D', m, n, visited);
    dfs(i, j-1, s + 'L', m, n, visited);
    dfs(i, j+1, s + 'R', m, n, visited);
    
    visited[i][j] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<vector<int> > visited(n, vector<int> (n));
    
    if(m[0][0] == 0) return v;
    if(m[n-1][n-1] == 0) return v;
    string s = "";
    
    dfs(0, 0, s, m, n, visited);
    
    sort(v.begin(), v.end());
    return v;
}

int main() {
        int n;
        cout<<"Enter size of matrix: "<<endl;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        
        cout<<"Enter the elements only '0' ans '1': "<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        
        vector<string> result = findPath(m, n);
        sort(result.begin(), result.end());
        cout<<"The path the rat has taken to reach the destination is: "<<endl;
        
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
        
    return 0;
}