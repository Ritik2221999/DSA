// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, vector<int> adj[]) {
    unordered_map<int, int> parent;
    
    parent[src] = -1;
    visited[src] = 1;
    
    queue<int> q;
    q.push(src);
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        for(auto neighbour: adj[front]) {
            if(visited[neighbour] && neighbour != parent[front])
                return true;
            else if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    // Code here
    unordered_map<int, bool> visited;
    
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            bool ans = isCyclicBFS(i, visited, adj);
            
            if(ans == 1)
                return true;
        }
    }
    return false;
}

int main() {
        int V, E;
        cout<<"Enter number of vertices: "<<endl;
        cin >> V;
        
        cout<<"Enter number of Edges: "<<endl;
        cin>>E;
        
        cout<<"Enter the nodes connecting each other: "<<endl;
        
        vector<int> adj[V];
        // adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} -> input
        
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ans = isCycle(V, adj);
        cout<<"If cycle present: '1' if Not: '0': ";
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    return 0;
}