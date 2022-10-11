#include<bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    for(int i=0; i<m; i++) {
            bool flag = 0;
        for(int j=0; j<n; j++) {
            if(a2[i] == a1[j]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return "No";
    }
    return "Yes";
}

int main() {
    int a1[5] =  {10, 5, 2, 23, 19};    //{11, 1, 13, 21, 3, 7};
    int a2[3] =  {19, 5, 3};  // {11, 3, 7, 1};
    
    string result = isSubset(a1, a2, 5, 3);
    cout<<result<<endl;
    return 0;
}