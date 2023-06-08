// - Declare 2D vector ans, insert first two vectors {1}, {1,1}
// - Now use for loop to insert each new row in the ans,
//     1. first declare 1D vector temp, which is a new row of triangle
//     2. insert 1 into temp, then calculate next (rowIndex-1) elements from above row of triangle.
        
//         ie.  here i is the row no. 
        
//     3. insert 1 again as the last element into temp
// - Now insert this temp into ans as the new row2 of triangle.

// - Time complexity :  O(N^2)


#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>>ans(n);
  
  if(n == 1)
      return {{1}};
  ans[0] = {1};
  ans[1] = {1,1}; 
  for(int i = 2; i < n; i++){
    ans[i].resize(i+1);
    ans[i][0] = 1;
    for(int j = 1; j < i; j++){
      long long int sum = ans[i-1][j-1]+ans[i-1][j];
      ans[i][j] = sum;
    }
    ans[i][i] = 1;
  }
  return ans;
}
