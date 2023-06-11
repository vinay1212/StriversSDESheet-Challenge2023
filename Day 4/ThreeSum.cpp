#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.

	sort(arr.begin(), arr.end());
	vector<vector<int>>ans;
	set<vector<int>>s;
	for(int i = 0; i < n-2; i++){
		int tar = K-arr[i];
		int l = i+1, r = n-1;
		while(l<r){
			int temp = arr[l]+arr[r];
			if(temp == tar){
				vector<int> v = {arr[i], arr[l++], arr[r--]};
				sort(v.begin(), v.end());
				s.insert(v);
			}
			else if(temp > tar){
				r--;
			}
			else{
				l++;
			}
		}
	}
	for(auto it : s){
		ans.push_back(it);
	}
	return ans;
}
