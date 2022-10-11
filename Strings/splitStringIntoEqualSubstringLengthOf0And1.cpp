#include<bits/stdc++.h>
using namespace std;

int maxSubStr(string str, int n) {
    int count0 = 0, count1 = 0;
    int counter = 0;
    
    for(int i=0; i<n; i++) {
        if(str[i] == '0')
            count0++;
        else
            count1++;
            
        if(count0 == count1)
            counter++;
    }
    
    if(count0 != count1)
        return -1;
        
    return counter;
}

int main() {
    
    string str = "0100110101";
    int n = str.length();
    
    cout<<"The length of equal substring of 0's and 1's is: "<<endl;
    cout<<maxSubStr(str, n);
}