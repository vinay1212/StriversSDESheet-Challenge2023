// - create 2 variable, sum and maxsum
// - run a for loop over the array, and add the element to sum,
//     - if sum > maxsum —> maxsum = sum
//     - if sum < 0 —> sum = 0
// - thats it, after the loop return the maxsum.

// - Time complexity : O(N)

// eg. {-5, 4, 6, -3, 4, -1}

// sub                                   sum                           maxsum

// {-5}                                  -5(<0)                              0                   sum < 0 leave the subarray

// {4}                                      4                                    4

// {4, 6)                                  10                                  10

// {4, 6, -3}                              7                                   10

// {4, 6, -3, 4}                          11                                 11

// {4, 6, -3, 4, -1}                     10                                 11

// so maxsum = 11


#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long maxsum = 0;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > maxsum)
            maxsum = sum;
        if(sum < 0)
            sum = 0;
    }
    return maxsum;
}
