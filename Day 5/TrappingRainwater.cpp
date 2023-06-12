#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.

    vector<long> l, r(n, 0);
    long mx = arr[0];
    l.push_back(mx);
    for(int i = 1; i < n; i++){
        if(arr[i] > mx){ 
            mx = arr[i];
        }
        l.push_back(mx);
    }
    mx = arr[n-1];
    r[n-1] = mx;
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > mx){
            mx = arr[i];
        }
        r[i] = mx;
    }
    long ans = 0;
    for(int i = 0; i < l.size(); i++){
        // cout<<l[i]<<" "<<r[i]<<endl;
        ans += (long)min(l[i], r[i])-(long)arr[i];
        // cout<<ans<<endl;
    }
    
    return ans;
}
