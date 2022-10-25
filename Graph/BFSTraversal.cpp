// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002
#include<bits/stdc++.h>
using namespace std;

void preparedAdjList(unordered_map<int, set<int> > &adjList, 
            vector<pair<int, int> > &edges) {

    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}


void bfs(unordered_map<int, set<int> > &adjList, unordered_map<int, bool> &visited,
        vector<int> &ans, int node) {
    
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        
        // store frontNode to ans
        ans.push_back(frontNode);
        
        // traverse all neighbours of frontNode
        for(auto i: adjList[frontNode]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int> > edges) {
    unordered_map<int, set<int> > adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    preparedAdjList(adjList, edges);
    
    // traverse all components of a graph
    for(int i=0; i<vertex; i++) {
        if(!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}


int main() {
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    
    // graph g;
    vector<int> ans;
    
    vector<pair<int, int> > vec = {{0, 1}, {0, 3}, {2, 0}, {3, 4}, {5, 6}, {6, 7}, {7, 5}};
    
    ans = BFS(n, vec);
    
    cout<<"the BFS traversal of graph is: "<<endl;
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    
    
    return 0;
}


// *****************************************************************************************

// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        vis[0] = 1;
        
        queue<int> q;
        q.push(0);
        
        vector<int> ans;
        
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            
            // store frontNode into ans
            ans.push_back(frontNode);
            
            // traverse all neighbours of frontNode
            for(auto i: adj[frontNode]) {
                if(!vis[i]) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        return ans;
    }
};

int main() {
    int tc;
    cout<<"Enter number of test cases: "<<endl;
    cin >> tc;
    while (tc--) {
        int V, E;
        cout<<"Enter number of node and then edges: "<<endl;
        cin >> V >> E;

        vector<int> adj[V];

        cout<<"Enter the nodes that are connected through edges: "<<endl;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            //      adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        cout<<"The BFS traversal of graph is: "<<endl;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}