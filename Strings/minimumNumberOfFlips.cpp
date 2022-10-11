#include<bits/stdc++.h>
using namespace std;

int minFlips(string str) {
    int count1 = 0;
    int count2 = 0;
    
    int element = '0';
    for(int i=0; i<str.length(); i++) {
        if(str[i] != element)
            count1++;
        else
            count2++;
            
        if(element == '0')
            element = '1';
        else
            element = '0';
    }
    return min(count1, count2);
}

int main() {
    string str ="0001010111";
    cout<<"Minimum number of bits to be flipped is: "<<endl;
    cout<<minFlips(str);
    return 0;
}
