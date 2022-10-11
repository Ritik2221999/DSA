// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n) {
    int deficit = 0;  // how much petrol we lack to move to next station
    int balance = 0;
    int start = 0;
    
    for(int i=0; i<n; i++) {
        balance += p[i].petrol - p[i].distance;
        
        if(balance < 0) {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    
    if(deficit + balance >= 0)
        return start;
    return -1;
}
    
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}