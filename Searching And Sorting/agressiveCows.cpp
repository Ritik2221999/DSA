// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0];
    
    for(int i=0; i<stalls.size(); i++) {
        if(stalls[i] - lastPos >= mid) {
            cowCount++;
            // k -> total no f cows
            if(cowCount == k) {
                return true;
            }
            lastPos = stalls[i]; // place a new cow to new position
        }
    }
    return false;
}

int agressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    
    int s = 0;
    int maxi = -1;
    
    for(int i=0; i<stalls.size(); i++) {
        maxi = max(maxi, stalls[i]);
    }
    
    int e = maxi;
    int mid = s + (e - s)/2;
    int ans = -1;
    while(s < e) {
        if(isPossible(stalls, k, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

int main() {
    vector<int> stalls = {4, 2, 1, 3, 6};
    int k;
    cout<<"Enter the number of cows: "<<endl;
    cin>>k;
    
    cout<<"the largest minimum distance between any two cows is: "<<endl;
    cout<<agressiveCows(stalls, k);
    
    return 0;
}