#include <bits/stdc++.h> 
bool sortcol(const vector<int> &v1, const vector<int> &v2){
    if(v1[0] < v2[0])
        return true;
    else if(v1[0] > v2[0])
        return false;
    else if(v1[2] < v2[2])
        return true;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<vector<int>> v(start.size(), vector<int> (3, 0));
    for(int i = 0; i < start.size(); i++){
        v[i][0] = end[i];
        v[i][1] = start[i];
        v[i][2] = i+1;
    }
    sort(v.begin(), v.end(), sortcol);

    vector<int> ans;
    ans.push_back(v[0][2]);
    int prev = v[0][0];

    for(int i = 1; i < start.size(); i++){
        if(v[i][1] >prev){
            ans.push_back(v[i][2]);
            prev = v[i][0];
        }
    }
    return ans;
}
