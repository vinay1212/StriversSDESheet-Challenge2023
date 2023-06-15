// - we will use greedy algorithm to solve this problem
// - sort the given activities according to their end time, now whatever may be the case the person is performing first activity
// - mark the end time of first activity, and keep count of activities
// - start a for loop from 1 to N
//     - check if current jobs start time is greater than or equal to prev’s end time
//         - if yes —> increment the count
//         - note down end time of current
// - return count

// - Time complexity : O( NlogN+N )




#include<bits/stdc++.h>
bool sortcol(pair<int,int> v1, pair<int, int>v2){
    return v1.second < v2.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int, int>>v;
    for(int i = 0; i < start.size(); i++){
        pair<int, int> p;
        p.first = start[i];
        p.second = finish[i];
        v.push_back(p);
    }
    sort(v.begin(), v.end(), sortcol);

    int count = 1;
    int prev = v[0].second;
    for(int i = 0; i < v.size(); i++){
        if(v[i].first >= prev){
            count++;
            prev = v[i].second;
        }
    }
    return count;
}
