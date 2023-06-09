#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> v;
   for(int i = 0; i < arr.size(); i++){
      for(int j = i+1; j < arr.size(); j++){
         if(arr[i] + arr[j] == s){
            if(arr[i] <= arr[j]){
               v.push_back({arr[i], arr[j]});
            }
            else{
               v.push_back({arr[j], arr[i]});
            }
         }
      }
   }
   // sort(arr.begin(), arr.end());
   // int l = 0, r = arr.size()-1;
   // while(l < r){
   //    int mid = l+(r-l)/2;
   //    if(arr[l] + arr[r] == s){
   //      v.push_back({arr[l], arr[r]});
   //      l++;
   //      r--;
   //    }
   //    else if(arr[l]+arr[r] > s){
   //       r--;
   //    }
   //    else{
   //       l++;
   //    }
   // }
   
   sort(v.begin(), v.end());
   return v;
}
