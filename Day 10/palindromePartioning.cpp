#include<bits/stdc++.h>

void setpalindromes(string s, vector<vector<bool>>&dp){
    int n = s.size();

    for(int i = 0 ; i < n; i++){
        dp[i][i] = true;
    }

    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = true;
        }
    }

    for(int i = 2; i <= n-1; i++){
        for(int j = 0; j+i < n; j++){
            dp[j][j+i]= dp[j+1][j+i-1] && (s[j] == s[j+i]);
        }
    }
}

void solve(int idx, string s, vector<string>str, vector<vector<bool>>&dp, vector<vector<string>>&ans){
    if(idx == s.size()){
        ans.push_back(str);
        return;
    }

    for(int i = 1; i <= (s.size()-idx); i++){
        string temp = s.substr(idx, i);
        string temp2 = temp;
        reverse(temp2.begin(), temp2.end());
        if(temp != temp2)
            continue;
        str.push_back(temp);
        solve(idx+i, s, str, dp, ans);
        str.pop_back();
    }
}

vector<vector<string>> partition(string s) {
    // Write your code here.
    vector<vector<string>>ans;
    vector<string> str;
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    setpalindromes(s, dp);

    solve(0, s, str,dp, ans);
    return ans;


}
