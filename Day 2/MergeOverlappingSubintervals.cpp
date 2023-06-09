// ### Approach1:

// - first we will sort the 2D vector according to starting points of each interval.
// - create new 2D vector ans,
// - start a while loop on interval.
//     - create 2 variables, a = starting point of interval i, b = ending point of interval i
//     - inside create another while loop running till the starting point of next element is smaller than or equal to b(end point of current element)
//     - b equal to max( interval[i+1][1] , b) (there could be case [1,10] [2,3] )
//     - push {a,b} to ans
//     - Time complexity : O(N*logN)

// Function to Sort 2D vector —>

// `*bool sortcol( const vector<int> &v1, const vector<int> &v2){*`

// `*if(v1[0] < v2[0])*`

// `*return true;*`

// `*return false*`

// `*}*`

// ### Approach2:

// - create 2D vector ans
// - start a for loop,
//     - check if end point of current element is greater than starting point of next element —>
        
//         intervals[i+1] = {starting point of current , max(end point of current, end point of next)
        
//     - else, its an independent interval insert it into ans vector



#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/


bool sortcol(const vector<int> &v1, const vector<int> &v2){
    if(v1[0] < v2[0])
        return true;
    return false;
}
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(), intervals.end(), sortcol);
    vector<vector<int>>v;
    
    // int i = 0;
    // while(i < intervals.size()){
    //     int a = intervals[i][0], b = intervals[i][1];
    //     while(i+1 < intervals.size() && (intervals[i+1][0] <= b)){
    //         b = max(intervals[i+1][1], b);
    //         i++;
    //     }
    //     v.push_back({a,b});
    //     i++;
    // }

    for(int i = 0; i < intervals.size(); i++){
        if(i+1 < intervals.size() && intervals[i][1] >= intervals[i+1][0]){
            intervals[i+1] = {intervals[i][0], max(intervals[i][1], intervals[i+1][1])};
        }
        else    
            v.push_back(intervals[i]);
    }
    return v;
}
