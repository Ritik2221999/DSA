#include<bits/stdc++.h>
using namespace std;

int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
    unordered_set<int> s;
    
    for(int i=0; i<n; i++) {
        s.insert(a[i]);
    }
    
    int count = 0;
    for(int i=0; i<m; i++) {
        int key = b[i];
        if(s.find(key) != s.end()) {
            count++;
            s.erase(key); // we are doing this because our b[] array dont have
                              // duplicate keys e.g. {1, 4, 2, 3, 5, 4} and dont make count more than 1
        }
    }
    return count;
}

int main() {
    int a[] = {89, 24, 75, 11, 23};
    int b[] = {89, 2, 4};
    
    cout<<"Intersection of two arrays is: "<<endl;
    cout<<NumberofElementsInIntersection(a, b, 5, 3);
    return 0;
}