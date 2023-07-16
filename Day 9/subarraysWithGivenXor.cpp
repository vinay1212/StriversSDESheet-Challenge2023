#include <bits/stdc++.h>

int subarraysXor(vector<int> &a, int b)
{
    //    Write your code here.
    int cnt = 0;
    int xr = 0;

    map<int, int> mp;
    mp[0] = 1;

    for(int i = 0; i < a.size(); i++){
        xr = xr^a[i];
        int t = xr^b;

        if(mp[t] > 0){
            cnt += mp[t];
        }

        mp[xr]++;
    }

    return cnt;
}
