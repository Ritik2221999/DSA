#include<iostream>
using namespace std;

int pivotIndex(int num[], int n) {
    int sum = 0, left=0;
    
    for (int i=0; i<n; i++) {
        sum += num[i];
    }
    
    // (left==(sum-num[i]-left)) is used to check pivot)
    // left is use to check the sum of left most elemets before pivot
    // sum-num[i]-left is used to sum of right elemnets
    for (int i=0; i<n; i++) {
        if (left == (sum-num[i]-left)) 
            return i;
        left += num[i];
    }
    return -1;
};

int main() {
    int num[6] = {1, 7, 3, 6, 5, 6};
    int result = pivotIndex(num, 6);
    cout<<" The pivot element index is: "<<result<<endl;
    
    return 0;
}