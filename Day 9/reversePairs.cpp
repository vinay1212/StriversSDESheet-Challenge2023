// ### Approach1 :

// - simply run two for loops, for i & j, and count pairs where arr[i] > 2*arr[j]
// - here time complexity is high, we need to optimize it
// - Time complexity : O(N^2)

// ### Approach2 :

// - this question is similar to above question, just difference is we want nums[i] > 2*nums[j]
// - so similar to above we will use merge sort for this, first we will divide the array till the it becomes individual elements, now these single elements are already sorted, we we just need to merge them, but before merging them we will count the reverse pairs, present in these subarrays.
// - so before calling merge function we will call the countInversions function
//     - this function will also work similar to above, if element in subarray2 is smaller for first element of subarray1, it will smaller for all elements of subarray 1, as it is sorted, so all elements in subarray1 are either equal to or greater than first element, so eventually they all will be greater than first element of subarray2.
//     - eg.   6,13,21,25                   1,2.3,4,4, 5 ,9,11,13
        
//         .       ^                                               ^
        
//     - here we can see first element 6 is greater than 5 of sub2, so all elements after 6 in first array will be greater than 5 plus in addition they will have there own elements
//     - write similar function as above, & just difference is instead of inversion pair condition use reverse pair condition ie. (arr[i] > 2*arr[j])
// - Time complexity : O(2NlogN)



#include <bits/stdc++.h> 
void merge(int low, int mid, int high, vector<int>&arr, int &count){
	vector<int>v(high-low+1, 0);
	int l1 = low, l2 = mid+1, j = 0;
	
	while(l1 <= mid && l2 <= high){
		if(arr[l1] <= arr[l2]){
			v[j++] = arr[l1++];
		}
		else{
			v[j++] = arr[l2++];
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
	return;
}   

void countPairs(int low, int mid, int high, vector<int>& arr, int &count){
	int right = mid+1;
	for(int i = low; i <= mid; i++){
		while(right <= high && arr[i] > 2*arr[right]){
			right++;
		}
		count += (right - (mid+1));
	}
}
void divide(int low, int high, vector<int>&arr, int &count){
	if(low >= high)
		return;
	int mid = (low+high)/2;
	divide(low, mid, arr, count);
	divide(mid+1, high, arr, count);
	countPairs(low, mid, high, arr, count);
	merge(low, mid, high, arr, count);
}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	int cnt = 0;
	divide(0, n-1, arr, cnt);	
	return cnt;
}
