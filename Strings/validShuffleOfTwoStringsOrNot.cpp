#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s1, s2;
    cout<<"Enter string 1: ";
    cin>>s1;
    
    cout<<"Enter string 2: ";
    cin>>s2;
    
    string result;
    cout<<"Enter the resultant string: ";
    cin>>result;
    
    int l1 = s1.length();
    int l2 = s2.length();
    int lr = result.length();
    
    if((l1 + l2) != lr) cout<<"length of: "<<result<<" is not equal to : "<<s1<<" and "<<s2<<endl;
    else{
        int flag = 0;
        int i = 0; // pointer to string - 1
        int j = 0; // pointer to string - 2
        int k = 0; // pointer to resultant string
        
        while(k < lr) {
            if(i < l1 && s1[i] == result[k]) i++;
            else if (j < l2 && s2[j] == result[k]) j++;
            else {
                flag = 1;
                break;
            }
            k++;
        }
        
        if(i < l1 or j < l2) cout<<"No: "<<result<<" string is not valid shuffle of: "<<s1<<" and "<<s2<<endl;
        else cout<<"Yes: "<<result<<" string is valid shuffle of: "<<s1<<" and "<<s2<<endl;
    }
}

int main() {
    solve();
    return 0;
}