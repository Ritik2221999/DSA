// https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int> > &edges, int src, int dest) {
    // create adj list 
    unordered_map<int, list<int> > adj;
    
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // do BFS
    unordered_map<int , bool> visited;
    unordered_map<int, int> parent;
    
    queue<int> q;
    q.push(src);
    
    parent[src] = -1;
    visited[src] = true;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        for(auto neighbour: adj[front]) {
            if(!visited[neighbour]) {
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }
    
    // prepare shortest path 
    vector<int> ans;
    int currNode = dest;
    ans.push_back(dest);
    
    while(currNode != src) {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int src = 1;
    cout<<"Given source node  is: "<<src<<endl;
    
    int dest = 8;
    cout<<"Given dest node is: "<<dest<<endl;
    
    vector<pair<int, int> > edges = {
        {1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 8}, {4, 6}, {6, 7}, {3, 8}, {5, 8}, {7, 8}
    };
    
    vector<int> res = shortestPath(edges, src, dest);
    
    cout<<"The shortest path in given graph is: "<<endl;
    for(auto i: res)
        cout<<i<<" ";
    
    return 0;
}