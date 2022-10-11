#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main() {
   unordered_map<string, int> umap;
   umap["price"] = 44;
   umap["gfg"] = 12;
   umap["gee"] = 10;
   
   for(auto it: umap) {
       cout<<it.first<<" -> "<<it.second<<endl;
   }
   
   cout<<"*********************************************"<<endl;
   for(auto it=umap.begin(); it != umap.end(); it++) {
       cout<<it -> first<<" "<<it -> second<<endl;
   }
   
   cout<<"********************************************"<<endl;
   string key = "gfg";
   if(umap.find(key) != umap.end()) {
       cout<<"key found: "<<endl;
   }
   else {
       cout<<"key not found: "<<endl;
   }
   
   
   if(umap.find(key) != umap.end()) {  // find() returns an iterator i/e. pointer
       auto temp = umap.find(key);
       cout<<"key is: "<<temp -> first<<endl;
       cout<<"Element is: "<<temp -> second<<endl;
   }
   cout<<"*******************************************"<<endl;
   umap.insert(make_pair("mobile", 17000));
   for(auto it: umap) {
       cout<<it.first<<" -> "<<it.second<<endl;
   }
   
   cout<<"*****************************************"<<endl;
   int arr[] = {7, 1, 0, 3, 5, 0, 1, 3, 2, 5, 7, 3, 8, 9, 0};
   unordered_map<int, int> umaped;
   
   for(int i=0; i<15; i++) {
       int key = arr[i];
       umaped[key]++;
   }
   
   for(auto it=umaped.begin(); it!=umaped.end(); it++) {
       cout<<it -> first <<" "<<it -> second<<endl;
   }
    return 0;
}