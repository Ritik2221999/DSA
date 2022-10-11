// https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}

char* reverse(char *S, int len)
{
    //code here
    stack<int> s;
    
    for(int i=0; i<len; i++) {
        char ch = S[i];
        s.push(ch);
    }
    
    for(int i=0; i<len; i++) {
        S[i] = s.top();
        s.pop();
    }
    
    return S;
}