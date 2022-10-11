#include<bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n) {
    set<int> sq;

    for(int i=0; i<n; i++) {
        sq.insert(arr[i]);
    }
    
    int longestStreak = 0;
    for(int i=0; i<n; i++) {
        if(!sq.count(arr[i] - 1)) {
            int currentNum = arr[i];
            int currentStreak = 1;
            
            while(sq.count(currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}

int main() {
    
    int n;
    cout<<"Enter the number of elements in array: "<<endl;
    cin>>n;
    // a[] = {2,6,1,9,4,5,3}
    
    int a[20];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    
    int result = findLongestConseqSubseq(a, n);
    
    cout<<"The longest consecutive Subsequence in array of length is: "<<endl;
    cout<<result;
    
    return 0;
}