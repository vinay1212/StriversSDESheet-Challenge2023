// - we have to maximize the profit, so we will use greedy algo to solve this problem
// - sort the given jobs according to their profits in descending order
// - now create array having size equal to largest deadline, initialize to 0
// - start a for loop on given jobs
//     - prefer to perform each job on its last day, if last day is not possible then check for second last, day, third last day and so on.
//     - when job is performed on certain day, mark that day as visited in array.


#include <bits/stdc++.h> 
bool sortcol(const vector<int> v1, const vector<int> v2){
    if(v1[1] > v2[1])
        return true;
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end(), sortcol);
    int j = 0;
    int profit = 0;
    int x = 0;
    while(x < jobs.size()){
        j = max(j, jobs[x][0]);
        x++;
    }
    vector<int> v(j, 0);
    for(int i = 0; i < jobs.size(); i++){
        int q = jobs[i][0]-1;
        if(v[q] == 0){
            profit += jobs[i][1];
            v[q] = 1;
        }
        else{
            int e = q;
            while(e >= 0 && v[e] != 0){
                e--;
            }
            if(e >= 0){
                profit += jobs[i][1];
                v[e] = 1;
            }
            
            
        }
    }
    return profit;
}
