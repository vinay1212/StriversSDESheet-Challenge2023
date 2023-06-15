// - sort the given items according to descending order of value/weight ratio of items
// - this will arrange items having max value per unit of weight at first position.
// - now run a for loop
//     - if weight of current element is less than or equal to W(remaining knapsack capacity) —> add resp value to ans, and subtract its weight from W(remaining knapsack capacity)
//     - it will only go in else part when W(remaining capacity is less than current element weight. —> calculate how much part of current element is required to fill knapsack and add that part of its resp value to ans.
// - Time complexity : O(NlogN)


#include <bits/stdc++.h> 
bool sortcol(const pair<int, int>&v1, const pair<int, int>&v2){
  double a = (double)v1.second/(double)v1.first;
  double b = (double)v2.second/(double)v2.first;
  return a>b;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    sort(items.begin(), items.end(), sortcol);
    double ans = 0;
    int weight = 0;
    for(int i = 0; i < n; i++){
      // cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
      if(items[i].first <= w){
        w -= items[i].first;
        ans += items[i].second;
      }
      else{
        ans += w*((double)items[i].second/items[i].first);
        w = 0;
        break;
      }
    }
    return ans;
}
