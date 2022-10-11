#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;  // insertion done in randomized order 
    s.insert(10);         // duplicate keys are not allowed
    s.insert(20);
    s.insert(5);
    s.insert(12);
    
    for(auto it=s.begin(); it!=s.end(); it++) {
        cout<<(*it)<<endl;
    }
    
    cout<<"Number of elements: "<<s.size()<<endl;
    
    // s.clear(); // remove the whoe unordered_set;
    cout<<"Number of elements: "<<s.size()<<endl;
    
    int key = 20;
    if(s.find(key) == s.end()) {
        cout<<"Key not found: "<<endl;
    }
    else {
        cout<<"key found: "<<endl;
    }
    
    if(s.find(key) != s.end())   // find() function return the iterator to that element
        cout<<"key found: "<<endl;
        
    if(s.count(5)) {
        cout<<"key found: "<<endl;   // count() fxn return '1' if it is present else '0' if not present
    }
    else {
        cout<<"Key not found: "<<endl   ; 
    }
    
    int deleted_key = 12;
    s.erase(deleted_key);  // remove the key passed in function
    cout<<"Number of elements: "<<s.size()<<endl;
    return 0;
}