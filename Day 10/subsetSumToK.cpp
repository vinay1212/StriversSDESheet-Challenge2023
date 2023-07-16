// - find all subsequences & carry there sum along with them, at the end if any subsequences found with final sum as K, return that subsequences
// - need to carry variable sum, and resp array of subsequence



#include<bits/stdc++.h>

void fun(int idx, int n, int k, vector<int>&arr, int sum, vector<int>v, vector<vector<int>>&ans){
    if(idx == n){
        if(sum == k){
            ans.push_back(v);
        }
        return;
    }

    sum += arr[idx];
    v.push_back(arr[idx]);
    fun(idx+1, n, k, arr, sum, v, ans);
    sum -= arr[idx];
    v.pop_back();
    fun(idx+1, n, k, arr, sum, v, ans);

}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int> v;
    int sum = 0;

    fun(0, n, k, arr, sum, v, ans);

    return ans;
}
