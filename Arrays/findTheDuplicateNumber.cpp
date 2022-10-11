#include<bits/stdc++.h>
using namespace std;

// Time Complexit -> O(n)

// int findDuplicate(vector<int>& nums) {
//     while(nums[0] != nums[nums[0]]) {
//         swap(nums[0], nums[nums[0]]);
//     }
//     return nums[0];
// }


// Time Complexit -> O(logn)
int findDuplicate(vector<int>& nums) {
   
   auto less_or_equal = [&](int cur) {
       int count = 0;
       for(auto &num: nums) {
           if(num<=cur){
               count++;
           }
           
       }
       return count;
   };
   
   int low = 1, high = nums.size();
   int dupli = -1;
   
   while(low <= high) {
       int cur = (low+high)/2;
       
       if(less_or_equal(cur) > cur) {
           dupli = cur;
           high = cur-1;
       }
       else {
           low = cur+1;
       }
   }
   return dupli;
}

int main() {
    
    vector<int> nums;
    
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(2);
    
    int duplicate = findDuplicate(nums);
    
    cout<<"the repeated number is: "<<duplicate<<endl;
    
    return 0;
}