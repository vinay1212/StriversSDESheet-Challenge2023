
// ### Approach1:

// - add the elements of arr2 at the end of arr1, starting from idx m
// - now the array is whole, then sort the array,

// - Time complexity :  O(n*log n)
  
  
#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int l = m, r = 0, t = 0;
	for(int i = 0; i < n; i++){
		arr1[l++] = arr2[i];
	}
	sort(arr1.begin(), arr1.end());
	return arr1;
}
