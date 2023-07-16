// ### Approach1 :

// - simply run two for loops, for i & j, and count pairs where arr[i] > arr[j]
// - here time complexity is high, we need to optimize it
// - Time complexity : O(N^2)

// ### Approach2 :

// - here we will use merge sort to count inversion pairs,
// - first divide the given array till the individual element, then while merging it we will calculate the the number of inversion pairs
// - before calling the merge function on 2 subarrays, we will call inversionCount function
//     - this function will take, low, mid and high pointer, array & count as paraments
//     - for this it will consider 2 subarrays, one from low to mid another from mid+1 to high
//     - now, it it both these subarrays will be in sorted order by themselves
//     - for each element in subarray 1, we need to find how many smaller elements are there in subarray 2, these will be the inversion pairs
//     - run for loop on subarray1,ie. low to mid,
//     - inside use another loop to check how many elements in subarray 2 can make inversion pair with it, here right = mid+1 (current pointer)
//     - we will add total count of numbers, ie. (right-(mid+1)) right = current idx, and return it at end
// - then call the merge function on these 2 subarrays
// - Time complexity : O(2N*logN)





#include <bits/stdc++.h> 

void merge(int low, int mid, int high, long long *arr, long long &count){
    vector<long long>v(high-low+1, 0);

    int l1 = low, l2 = mid+1;
    int j = 0;
    while(l1 <= mid && l2 <= high){
        if(arr[l1] <= arr[l2]){
            v[j++] = arr[l1++];
        }
        else{
            v[j++] = arr[l2++];
            // count += (mid-l1+1);
        }
    }
    while(l1 <= mid){
        v[j++] = arr[l1++];
    }
    while(l2 <= high){
        v[j++] = arr[l2++];
    }

    for(int i = 0, k = low; i < v.size(); i++, k++){
        arr[k] = v[i];
    }

}
void countPairs(int low, int mid, int high, long long *arr, long long &count){
    int right = mid+1;
    for(int i = low; i <= mid; i++){
        while(right <= high && arr[i] > arr[right]){
            right++;
        }
        count += right-(mid+1);
    }
}
void divide(int low, int high, long long *arr, long long &count){
    if(low >= high)
        return;
    int mid = (low + high)/2;
    divide(low, mid, arr, count);
    divide(mid+1, high, arr, count);
    countPairs(low, mid, high, arr, count);
    merge(low, mid, high, arr, count);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long count = 0;
    divide(0, n-1, arr, count);
    return count;
}
