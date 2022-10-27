// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626

#include<bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, 
                unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int> > &adj) {
    
    visited[node] = true;
    dfsVisited[node] = true;
    
    for(auto neighbour: adj[node]) {
        if(!visited[neighbour]) {
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
            
            if(cycleDetected)
                return true;
        }
        else if(dfsVisited[neighbour])
            return true;
    }
    // when returning from recursion mark that node to false 
    dfsVisited[node] = false;
    return false;
}

// using DFS
int detectCycleInDirectedGraph(int n, vector<pair<int, int> > &edges) {
    // create a adj list 
    unordered_map<int, list<int> > adj;
    
    for(int i=0; i<n; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    
    // call for dfs for all the components
    
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            bool checkCycle = checkCycleDFS(i, visited, dfsVisited, adj);
            
            if(checkCycle)
                return true;
        }
    }
    return false;
}

int main() {
    int n = 5;
    cout<<"The number of nodes are: "<<n<<endl;
    
    vector<pair<int, int> > edges = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
    // vector<pair<int, int> > edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {2, NULL}, {1, NULL}, {1, 2}};
    
    int ans = detectCycleInDirectedGraph(n, edges);
    
    if(ans) {
        cout<<"Cycle is present: "<<endl;
    }
    else
        cout<<"No cycle is present: "<<endl;
    
    return 0;
}