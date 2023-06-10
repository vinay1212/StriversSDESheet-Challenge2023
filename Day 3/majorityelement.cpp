#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.

	// map<int,int>mp;
	// for(int i = 0; i < n; i++){
	// 	mp[arr[i]]++;
	// }
	// for(auto it : mp){
	// 	if(it.second > n/2){
	// 		return it.first;
	// 	}
	// }
	// return -1;

	// sort(arr, arr+n);
	// int count = 1, mx = 1, mxe = arr[0];
	// int prev = arr[0];
	// for(int i = 1; i < n; i++){
	// 	if(arr[i] == prev){
	// 		count++;
	// 		if(count> mx){
	// 			mx = count;
	// 			mxe = arr[i];
	// 		}
	// 	}
	// 	else{
	// 		prev = arr[i];
	// 		count = 1;
	// 	}
	// }
	// if(mx > n/2)
	// 	return mxe;
	// return -1;

	int majority = 0, count = 0;
	for(int i = 0; i < n; i++){
		if(count == 0){
			majority = arr[i];
			count++;
		}
		else{
			if(arr[i] == majority){
				count++;
			}
			else{
				count--;
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] == majority){
			cnt++;
		}
	}
	if(cnt > n/2)
		return majority;
	return -1;
}
