#include <bits/stdc++.h> 
void sm(vector<int> num, int l, int r, vector<int>&ans, int sum = 0){
    if(l > r){
        ans.push_back(sum);
        return;
    }
    sm(num, l+1, r, ans, sum+num[l]);
    sm(num, l+1, r, ans, sum);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int>ans;
    sm(num, 0, num.size()-1,ans);
    sort(ans.begin(), ans.end());
    return ans;
}
