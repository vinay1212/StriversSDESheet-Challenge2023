// ### Approach1:

// - Create 3 variables, run a for loop & count 0s, 1s and 2s separately
// - run a for loop on array again & change the respective no. of elemnts of array to 0,1,2 as counted 0s, 1s, & 2s.
// - Time complexity : O(N)

// ### Approach2:

// - run a while loop where i ≤ r, i, l= lower index & r = higher index
// - Basic idea is to move all 0s to the left of the array & all 2s to the right of the array, soo the rest 1s will get automatically sorted.
// - start from i = 0;
//     - if arr[i] == 0 —> swap(arr[i] , arr[l++])
//     - if arr[i] == 2 —> swap(arr[i] , arr[r- -])
// - this will sort the given array
// - Time complexity : O(log n)




#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   // int zeros = 0, ones = 0, twos = 0;
   // for(int i = 0; i < n; i++){
   //    if(arr[i] == 0)
   //       zeros++;
   //    else if(arr[i] == 1)
   //       ones++;
   //    else
   //       twos++;
   // }
   // for(int i = 0; i < zeros; i++)
   //    arr[i] = 0;
   // for(int i = zeros; i < zeros+ones; i++)
   //    arr[i] = 1;
   // for(int i = zeros+ones; i < zeros+ones+twos; i++)
   //    arr[i] = 2;
   int l = 0, r = n-1;
   int  i = 0;
   while(i <= r){
      if(arr[i] == 0){
         swap(arr[i++], arr[l++]);
      }
      else if (arr[i] == 1) {
        i++;
      }
      else{
         swap(arr[r--], arr[i]);
      }
   }
}
