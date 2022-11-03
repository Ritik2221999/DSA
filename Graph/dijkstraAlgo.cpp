// https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int> > &vec, int vertices, int edges, int source) {
    
    // create adj list 
    unordered_map<int, list<pair<int, int> >> adj;
    
    for(int i=0; i<edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    // creation of dist array with infinte vlaue's initially
    vector<int> dist(vertices);
    
    for(int i=0; i<vertices; i++) {
        dist[i] = INT_MAX;
    }
    
    // creation of set on basis(distance, node)
    set<pair<int, int> > st;
    
    // initialize set with distance and source node 
    dist[source] = 0;
    st.insert(make_pair(0, source));  // starting distance of source node is '0'
    
    while(!st.empty()) {
        auto top = *(st.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;
        
        // remove top record now
        st.erase(st.begin());
        
        // traverse on neighbours
        for(auto neighbour: adj[topNode]) {
            if(nodeDistance + neighbour.second < dist[neighbour.first]) {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                
                // if record found, then erase it 
                if(record != st.end())
                    st.erase(record);
                    
                // distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                
                // push record in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

int main() {
    int vertices = 4;
    int edges = 5;
    int source = 0;
    
    vector<vector<int> > vec = {
        {0, 1, 7}, {0, 2, 1}, {0, 3, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 1}, {3, 4, 7}
    };
    
    vector<int> result = dijkstra(vec, vertices, edges, source);
    
    cout<<"The Shortest path from source node to other nodes using Dijkstra Algo is: "<<endl;
    
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }cout<<endl;
    
    return 0;
}