#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    // vector<int> v;
    // for(int i = 0; i < matrix.size(); i++){
    //     for(int j = 0; j < matrix[i].size(); j++){
    //         v.push_back(matrix[i][j]);
    //     }
    // }
    // int t = v.size();
    // sort(v.begin(), v.end());
    
    // if(t%2 == 0)
    //     return v[(t/2)+1];
    // return v[t/2];



    int row = matrix.size();
    int col = matrix[0].size();
    int mn = INT_MAX, mx = INT_MIN;
    for(int i = 0; i < row; i++){
        mn = min(mn, matrix[i][0]);
        mx = max(mx, matrix[i][col-1]);
    }
    int l = mn, r = mx;

    while(l < r){
        int mid = (l+r)/2;
        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] <= mid)
                    count++;
                else
                    break;
            }
        }
        if(count >= (row*col+1)/2){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return l;
}
