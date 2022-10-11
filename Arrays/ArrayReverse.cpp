// complexity -> O(n)

#include<bits/stdc++.h>
using namespace std;

// Approach-1
void reverse(int arr[], int n) {
	int start = 0;
	int end = n-1;
	
	while(start<end) {
		swap(arr[start], arr[end]);
		start++;
		end--;
	}
}

void print(int arr[], int n) {
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

// Approach-2
void withoutSwap(int arr[], int n) {
	int start = 0;
	int end = n-1;
	
	while(start<end) {
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

int main() {
	int arr[6] = {2, 1, 5, 6, 4, 9};
	
	print(arr, 6);
	
	reverse(arr, 6);
	
	cout<<"Array after reversed is: "<<endl;
	
	print(arr, 6);
	
	
}
