#include<bits/stdc++.h>

int fact(int n){
    if(n <= 1)
        return 1;
    return n*fact(n-1);
}

void solve(string str, int n, vector<int>&mp, int k, string &s){
    if(str.size() == n){
        s = str;
        return;
    }

    int temp = fact(mp.size()-1);
    int t = k/temp;
    k = k - temp*t;
    str += to_string(mp[t]);
    mp.erase(mp.begin()+t);

    // for(auto it : mp)
    //     cout<<it<<" ";
    // cout<<endl;
    
    solve(str, n, mp, k, s);
}


string kthPermutation(int n, int k) {
    // Write your code here.
    vector<int>mp;
    for(int i = 0; i < n; i++){
        mp.push_back(i+1);
    }

    string str = "", s;
    solve(str, n, mp, k-1, s);
    return s;
}
