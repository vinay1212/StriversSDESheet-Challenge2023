#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here

  for(int i = 1; i < arr.size(); i++){
    arr[i] = arr[i] + arr[i-1];
  }
  int mx = 0;
  map <int, int> m;
  for(int i = 0; i < arr.size(); i++){
    if(arr[i] == 0)
      mx = i+1;
    else{
      if(m.find(arr[i]) != m.end()){
        mx = max(mx, i - m[arr[i]]);
      }
      else
        m[arr[i]] = i;
    }
  }
  // for(int i = 0; i < arr.size()-1; i++){
  //   for(int j = i+1; j < arr.size(); j++){
  //     if(arr[j] == 0)
  //       mx = max(j+1, mx);
  //     if(arr[i] == arr[j]){
  //       int t = j-i;   
  //       mx = max(mx, t);
  //     }
  //   }
  // }
  return mx;

}
