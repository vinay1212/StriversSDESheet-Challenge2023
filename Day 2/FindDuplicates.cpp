// ### Approach1:

// - create array temp of n-1 elements all containing 0
// - traverse the given array, and consider the element of given array as index for temp, make the index element increment by 1.
// - check if temp[arr[i]] == 2 —> return that element, bcoz it incremented the element 2 times, it means it occurred twice.

// - Time complexity : O(N)
// - space complexity : O(N)



#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.

	vector<int> v(n, 0);
	for(int i = 0; i < n; i++){
		if(v[arr[i]-1] > 0)
			return arr[i];
		if(v[arr[i]-1] == 0){
			v[arr[i]-1]++;
		}
	}
	return 0;
}
