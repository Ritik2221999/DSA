#include<bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m) {
    
    sort(a.begin(), a.end());
    long long min = INT_MAX;
    
    for(int i=0; i+m-1<n; i++) {
        int d = a[i+m-1] - a[i];
        
        if(d < min)
            min = d;
    }
    return min;

}

int main() {
    vector<long long> a = {3, 4, 1, 9, 56, 7, 9, 12};
    long long n = a.size();
    long long m;
    cout<<"Enter the number of students: "<<endl;
    cin>>m;
    
    cout<<findMinDiff(a, n, m);
    return 0;
}