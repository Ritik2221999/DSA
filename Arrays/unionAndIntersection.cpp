#include<iostream>
using namespace std;

void printUnion(int arr1[], int arr2[], int len1, int len2) {

    int f, i, j, k = 0;
    int arr3[100];
    for (i = 0; i < len1; i++) {
        arr3[k] = arr1[i];
        k++;
    }

    for (i = 0; i < len2; i++) {
        f = 0;
        for (j = 0; j < len1; j++) {
            if (arr2[i] == arr1[j]) {
                f = 1;
            }
        }
        if (f == 0) {
            arr3[k] = arr2[i];
            k++;
        }
    }
    cout << "Union of two array is:";
    for (i = 0; i < k; i++) {
        cout << arr3[i] << " ";
    }
}

// Optimized Union using STL **********************************************************

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        unordered_set<int> ans;
        
        for(int i=0; i<n; i++) {
            ans.insert(a[i]);
        }
        
        for(int i=0; i<m; i++) {
            ans.insert(b[i]);
        }
        int cnt = 0;
        for(auto i: ans) {
            cnt++;
        }
        return cnt;
    }
    
};

// ******************************************************************************************

void printIntersection(int arr1[], int arr2[], int len1, int len2) {

    int arr3[100];
    int i, j, k = 0;

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (arr1[i] == arr2[j]) {
                arr3[k] = arr1[i];
                k++;
            }
        }
    }
    cout << "\nIntersection of two array is:";
    for (i = 0; i < k; i++) {
        cout << arr3[i] << " ";
    }
}

// optimized intersection using STL ********************************

     int i=0; j=0;
     vector<int> ans;
    while(i<n && j<m) {
        if (arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return ans;
        
// ****************************************************************** 

int main() {

    int arr1[100];
    int arr2[100];
    int arr3[100];
    int i, j, len1, len2;

    cout << "Enter size of 1st array:";
    cin>>len1;

    cout << "Enter 1st array elements:";
    for (i = 0; i < len1; i++) {
        cin >> arr1[i];
    }
    cout << "Enter size of 2nd array:";
    cin>>len2;

    cout << "Enter 2nd array elements:";
    for (i = 0; i < len2; i++) {
        cin >> arr2[i];
    }

    printUnion(arr1, arr2, len1, len2);
    printIntersection(arr1, arr2, len1, len2);

    return 0;
}
