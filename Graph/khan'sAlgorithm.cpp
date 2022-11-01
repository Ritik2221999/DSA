// https://www.codingninjas.com/codestudio/problems/topological-sort_982938
#include<bits/stdc++.h>
using namespace std;

// Khan's Algorithm
vector<int> topologicalSort(vector<vector<int> > &edges, int v, int e) {
    
    // create Adj List
    unordered_map<int, list<int> > adj;
    
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    // find all indegrees
    vector<int> indegree(v);
    for(auto i: adj) {
        for(auto j: i.second)
            indegree[j]++;
    }
    
    // push all nodes having indegree zero
    queue<int> q;
    
    for(int i=0; i<v; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    
    // do BFS
    vector<int> ans;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        // ans store
        ans.push_back(front);
        
        // neighbour indegree store
        for(auto neighbour: adj[front]) {
            indegree[neighbour]--;  // means we are rying to remove the indegrees of nodes
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return ans;
}

int main() {
    int v = 6;
    int e = 6;
    
// '0' -> 1, '0' -> 2, '1' -> 3, '1' -> 4, '3' -> 4, '3' -> 5
    vector<vector<int> > edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {3, 4}, {3, 5}};
    
    vector<int> result = topologicalSort(edges, v, e);
    
    cout<<"Topological Sort using KHAN's algorithm: "<<endl;
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }cout<<endl;
    
    return 0;
}