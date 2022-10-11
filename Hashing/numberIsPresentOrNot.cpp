// You are given an array contains both positive and non - positive numbers, 
// elements are in he range - MAX to MAX - > MAX = 1000
// our task is to search if an number is present in array or not  in O(1) time

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

bool hashTable[MAX+1][2];  // contains 2 columns numbers and MAX+1 rows numbers i.e. [0 and 1] col

bool search(int x) {
    if(x >= 0) {  // if x is postive search in row 0
        if(hashTable[x][0] == 1)
            return true;
        else
            return false;
    }
    else {
        x = abs(x);
        if(hashTable[x][1] == 1)
            return true;
        else
            return false;
    }
}

void insert(int arr[], int n) {
    for(int i=0; i<n; i++) {
        if(arr[i] >= 0) {  // if number is positive put in row 0
            hashTable[arr[i]][0] = 1;
        }
        else {  // if number is negative put in row 1
            hashTable[abs(arr[i])][1] = 1;
        }
    }
}

int main() {
    int arr[] = {-1, 9, 2, -5, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    insert(arr, n);
    
    int find = -3;
    if(search(find)) {
        cout<<"Element is present: "<<endl;
    }
    else {
        cout<<"Element is not present: "<<endl;
    }
    return 0;
}