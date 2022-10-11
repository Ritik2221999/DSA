#include<bits/stdc++.h>
using namespace std;
#define N 4 
#define M 5


void printCommonElements(int mat[N][M]) {
    unordered_map<int, int> mp;
    
    for(int j=0; j<M; j++) {
        mp[mat[0][j]] = 1;
    }
    
    for(int i=1; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(mp[mat[i][j]] == i) {
                mp[mat[i][j]] = i+1;
                
                if(i == N-1) 
                    cout<<mat[i][j]<<" ";
            }
        }
    }
}

int main() {
    
    int mat[N][M] = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9}  
    };
    
    cout<<"Common elements in all rows are: ";
    printCommonElements(mat);
    return 0;
}