// ### Approach1 :

// - same as above approach, we will use pick and not pick method
// - if we pick the element we were allowed use the same element again, but here we can use the element only once, so if we pick element we need to shift to next element, and if we do not pick then also we need to shift to next element
// - here the question does not want duplicate entries, so first thing should strike to our mind is using set. insert all combination arrays summing to target into set, it will remove duplicate entries, then at the end return all entries of set.
// - Time complexity : O(2^n*(k*log(k)))
// - here the extra log(K) is inserting these target sum combination arrays into set.

// ### Approach 2:

// - first of all sort the array, as the ans should be in sorted format
// - starting with the 0th element, we have n-1 wats to pick the first element
// - check if current element can be added to our ds, if we can pick it move idx to idx+1, while moving the idx skip the next elements having same values as they can form a duplicate sequences
// - reduce the target by arr[idx], call recursive function on next element, and after call make sure to pop out element from ds.
// - at any point if element becomes greater than target, it means all element after current are greater as array is sorted, return as there is no use to check
// - base condition whenever target becomes zero, insert ds into ans




#include<bits/stdc++.h>
void fun(int idx, int n, vector<int>& arr, int sum,vector<int>v, int target, set<vector<int>>&s){
	if(idx >= n){
		if(sum == target){
			s.insert(v);
		}
		return;
	}
	sum += arr[idx];
	v.push_back(arr[idx]);
	fun(idx+1, n, arr, sum, v, target, s);
	sum -= arr[idx];
	v.pop_back();
	fun(idx+1, n, arr, sum, v, target, s);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	vector<vector<int>> ans;
	set<vector<int>>s;
	int sum = 0;
	vector<int>v;
	sort(arr.begin(), arr.end());

	fun(0, n, arr, sum, v, target, s);

	for(auto it : s){
		ans.push_back(it);
	}
	return ans;
}
#include<bits/stdc++.h>
void fun(int idx, int n, vector<int>& arr, int sum,vector<int>v, int target, set<vector<int>>&s){
	if(idx >= n){
		if(sum == target){
			s.insert(v);
		}
		return;
	}
	sum += arr[idx];
	v.push_back(arr[idx]);
	fun(idx+1, n, arr, sum, v, target, s);
	sum -= arr[idx];
	v.pop_back();
	fun(idx+1, n, arr, sum, v, target, s);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	vector<vector<int>> ans;
	set<vector<int>>s;
	int sum = 0;
	vector<int>v;
	sort(arr.begin(), arr.end());

	fun(0, n, arr, sum, v, target, s);

	for(auto it : s){
		ans.push_back(it);
	}
	return ans;
}
