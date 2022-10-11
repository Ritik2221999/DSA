#include<bits/stdc++.h>
using namespace std;

bool find3Numbers(int *arr, int n, int x) {
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            for(int k=j+1; k<n; k++) {
                if(arr[i] + arr[j] + arr[k] == x) {
                    cout<<"(Triplet is: "<<arr[i]<<", "<<arr[j]<<", "<<arr[k]<<")\n";
                    return true;
                }
            }
        }
    }
    return false;
}

void findTriplets(int A[], int n, int target) {
    
    sort(A, A+n);
    
    cout<<"Possible triplets are: "<<endl;
    for(int i=0; i<n-3; i++) {
        
        // remaining sum
        int k = target-A[i];
        
        // maintain two indices point
        int low = i+1, high = n-1;
        
        
        while(low < high) {
            if(A[low] + A[high] < k)
                low++;
            else if(A[low] + A[high] > k)
                high--;
            else {
                cout << "(" << A[i] << ", " << A[low] << ", " <<A[high] << ")\n";
                low++;
                high--;
            }
        }
    }
}

int main() {
    int x;
    cout<<"Enter the number whose triplet sum is in array: "<<endl;
    cin>>x;
    
    int arr[8] = { 2, 7, 4, 0, 9, 5, 1, 3 }; //{1, 4, 45, 6, 10, 8};
    
    cout<<find3Numbers(arr, 8, x)<<endl;
    
    findTriplets(arr, 8, x);
    
    
    return 0;
}