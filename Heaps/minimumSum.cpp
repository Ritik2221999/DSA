// https://practice.geeksforgeeks.org/problems/minimum-sum4058
#include<bits/stdc++.h>
using namespace std;

string sumString(string num1, string num2) {
    int n1 = num1.length()-1;
    int n2 = num2.length()-1;
    
    int carry = 0;
    string ans;
    
    // we are subtracting 48 to convert number to string \\ and adding 48 to convert string to number
    // ascii code of '0' = 48
    while(n1 >= 0 || n2 >= 0) {
        if(n1 < 0) {  // if num1 string is empty and n2 is left to add
            ans.push_back(((num2[n2] - 48 + carry) % 10) + 48);
            carry = (num2[n2] - 48 + carry)/10;
            n2--;
        }
        else if(n2 < 0) { // if num2 string is empty and n1 is left
            ans.push_back(((num1[n1] - 48 + carry) % 10) + 48);
            carry = (num1[n1] - 48 + carry)/10;
            n1--;
        }
        else { // if both string have elements to add
            ans.push_back(((num1[n1] - 48 + num2[n2] - 48 + carry) % 10) + 48);
            carry = (num1[n1] - 48 + num2[n2] - 48 + carry) / 10;
            n1--;
            n2--;
        }
    }
    if(carry) // if at last any carry is left add it to answer by converting it to number from string
        ans.push_back(carry + 48);
        
    reverse(ans.begin(), ans.end());
    return ans;
}

string solve(int arr[], int n) {
    // code here
    sort(arr, arr + n);
    
    string num1 = "";
    string num2 = "";
    
    for(int i=0; i<n; i++) {
        
        if(i % 2 == 0) {
            int num = arr[i];
            // we cant have zero's in front. e.g. 046, 005;
            if(arr[i] == 0 && num1.length() == 0) 
                continue;
            num1 += to_string(num);
        }
        else {
            int num = arr[i];
            
            if(arr[i] == 0 && num2.length() == 0)
                continue;
            num2 += to_string(num);
        }
    }
    return sumString(num1, num2);
}

int main() {
    int arr[] = { 6, 8, 4, 5, 2, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);
    
    string ans = solve(arr, N);
    cout<<"Minimum sum is: "<<endl;
    cout<<ans<<endl;
    
    return 0;
}