#include <bits/stdc++.h>

void fun(int idx, int n, vector<int>&arr, set<vector<int>>& s, vector<int> v){
    if(idx == n){
        sort(v.begin(), v.end());
        s.insert(v);
        return;
    }

    v.push_back(arr[idx]);
    fun(idx+1, n, arr, s, v);
    if(v.size() != 0)
        v.pop_back();
    fun(idx+1, n, arr, s, v);

}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>>ans;
    set<vector<int>>s;
    vector<int>v;
    fun(0, n, arr, s, v);

    for(auto it : s){
        ans.push_back(it);
    }
    return ans;
}
