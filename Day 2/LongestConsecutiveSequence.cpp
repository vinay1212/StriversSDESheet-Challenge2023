// ### Approach1:Using set

// - Insert all the elements in to the set, so all the duplicates will be deleted, and set will have only unique elements in sorted order.
// - while inserting the elements into sets find the smallest element
// - now run a loop on set, starting from first element, count = 1
//     - if curr element == prev+1 —>count++
//     - check if count > mx —>mx = count
//     - now if curr ≠ prev+1 —> count = 1
//     - prev = curr
// - at last return the mx, as the ans
// - Time complexity : O(N+___)

// ### Approach2:

// - sort the given array,
// - create 3 var, prev = arr[0], count = 1, mx = 1
// - run a for loop
//     - if the element equal to prev skip it
//     - if arr[i] == prev+1 —> count++
//     - else —>count = 1
//     - now check if count > mx —> mx = count
//     - at last change the prev value to curr array element

// return mx

// - Time complexity : O(NlogN + N)
// - space complexitty : O(1)



#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.

    sort(arr.begin(), arr.end());
    int prev = arr[0], count = 1, mx = 1;
    for(int i = 1; i < n; i++){

        if(arr[i] == prev+1)
            count++;
        else if(arr[i] != prev)
            count = 1;
        if(count > mx)
            mx = count;
        
        prev = arr[i];
    }
    return mx;
}
