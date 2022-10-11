#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<pair<int, int> > a;
    
    for(int i=0; i<n; i++) {
        int x, y;
        cin>>x>>y;
        a.push_back({x, y});
    }
    
    sort(a.begin(),a.end());
    
    stack<pair<int, int> > s;
    s.push({a[0].first, a[0].second});
    
    for(int i=1; i<n; i++) {
        int start1 = s.top().first;    // stack.top()
        int end1 = s.top().second;    // stack.top()
        int start2 = a[i].first;
        int end2 = a[i].second;
        
        if(end1 < start2) {
            s.push({start2, end2});
        }
        else {
            s.pop();
            end1 = max(end1, end2);
            s.push({start1, end1});
        }
    }
    
    cout<<"\n merged overlapping intervals are: "<<endl;
    while(!s.empty()) {
        cout<<s.top().first<<" "<<s.top().second<<endl;
        s.pop();
    }
    
    return 0;
}