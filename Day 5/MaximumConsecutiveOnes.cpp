#include<bits/stdc++.h>

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.

    // int max = INT_MIN;
    // for(int i = 0; i < n; i++){
    //     int sum = arr[i];
    //     int size = 1;
    //     for(int j = i+1; j < n; j++){
    //         sum += arr[j];
    //         size++;
    //         if(size-sum <= k){
    //             if(size > max)
    //                 max = size;
    //         }
    //     }     
    // }    
    // return max;

    int max = INT_MIN;
    int count = 0, j = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            count++;
        }

        while(count > k){
            j++;
            if(arr[j] == 0){
                count--;
            }
        }

        int size = i-j;
        if(max < size)
            max = size;
    }
    return max;
}
