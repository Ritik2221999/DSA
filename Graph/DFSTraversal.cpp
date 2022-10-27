// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, 
        unordered_map<int, list<int> > &adj, vector<int> &component) {
        
        // store ans
        component.push_back(node);
        
        visited[node] = 1;
        
        // recursive call for every connected node
        for(auto i: adj[node]) {
            if(!visited[i]) {
                dfs(i, visited, adj, component);
            }        
        }
}

vector<vector<int> > depthFirstSearch(int V, int E, vector<vector<int >> &edges) {
    // prepare adjList
    unordered_map<int, list<int> > adj;
    
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int> > ans;
    unordered_map<int, bool> visited;
    
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    int n = 5;
    cout<<"the number of nodes: "<<n<<endl;
    
    int m = 4;
    cout<<"the number of edges: "<<m<<endl;
    
    vector<vector<int> > edges = {{0, 2}, {0, 1}, {1, 2}, {3, 4}};
    
    vector<vector<int> > result = depthFirstSearch(n, m, edges);
    
    cout<<"The DFS traversal of disconnected graph is: "<<endl;
    
    for(int i=0; i<result.size(); i++) {
        cout<<"Disconnected graph: "<<i<<" -> ";
        for(int j=0; j<result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }cout<<endl;
    }
    
    
    return 0;
}