#include<bits/stdc++.h>
using namespace std;

int detectCycleInDirectedBFS(int n, vector<pair<int, int> > &edges) {
    // create adj list
    unordered_map<int, list<int> > adj;
    
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    
    // find all indegrees
    vector<int> indegree(n);
    for(auto i: adj) {
        for(auto j: i.second)
            indegree[j]++;
    }
    
    // push nodes having indegree zero
    queue<int> q;
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    
    // do BFS 
    int cnt = 0;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        // increment count
        cnt++;
        
        // neighbour indegree update
        for(auto neighbour: adj[front]) {
            indegree[neighbour]--;
            
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    if(cnt == n)
        return false;
    return true;
}

int main() {
    int n = 6;
    cout<<"Number of nodes: "<<n<<endl;
    
    vector<pair<int, int> > edges = {{0, 1}, {1, 2}, {1, 5}, {2, 3}, {3, 4}, {4, 0}, {4, 1}};
    
    if(detectCycleInDirectedBFS(n, edges)) {
        cout<<"Cycle is present: "<<endl;
    }
    else {
        cout<<"No cycle is present: "<<endl;
    }
    
    return 0;
}