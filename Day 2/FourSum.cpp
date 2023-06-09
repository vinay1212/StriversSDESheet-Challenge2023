// ### Apporach1:

// - create 4 iterated for loops, first starting from i = 0 to n-3, second from j = i+1 to n-2, third k = j+1 to n-1 & last from l = k+1 to n
// - find sum of each combination forming inside, if sum is equal to target—> return Yes
// - else return No at the end
// - Only problem with this approach is time complexity

// - Time complexity : O(N^4)

// ### Approach2:

// - here we will use the concept of problem 2 sum
// - firstly sort the given array.
// - create a for loop starting from i = 0 to n-2, and find integer target-arr[i]
// - inside create another for loop from j = i+1 to n-1, and find another integer s=target-arr[i]- arr[j]
// - now we will use the concept of 2 sum, by this we reduce time complexity by O(N)
// - create a while loop, l = j+1 and r = n-1
// - while(l < r)  —> if sum == s —>return true
// - return false if it comes out of loop

// - Time complexity : O(NlogN + N^3)


#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    // for(int i = 0; i < n-3; i++){
    //     for(int j = i+1; j < n-2; j++){
    //         for(int k = j+1; k < n-1; k++){
    //             for(int l = k+1; l < n; l++){
    //                 int sum = arr[i]+arr[j]+arr[k]+arr[l];
    //                 if(sum == target)
    //                     return "Yes";
    //             }
    //         }
    //     }
    // }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n-2; i++){
        int t = target-arr[i];
        for(int j = i+1; j < n-1; j++){
            int temp = t - arr[j];
            int l = j+1, r = n-1;
            while(l < r){
                int mid = l + (r-l)/2;
                if(arr[l]+arr[r] == temp)
                    return "Yes";
                else if(arr[l]+arr[r] > temp)
                    r--;
                else
                    l++;
            }
        }
    }
    return "No";
}
