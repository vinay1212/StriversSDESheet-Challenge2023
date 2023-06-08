// ### Approach1:

// - its a brute force approach, basically check all the possible pairs of combinations for buy and sell, then output the maximum out of it.
// - run a for loop i from 0 to n, inside run one more for loop from i+1 to n
    
//     calc prof = prices[j] - prices[i]
    
//     if prof > max —> max = prof
    
// - at the end return max
// - basically buying stock on first day, then selling it all days after buying & calc profit on each day, find max of it
    
//     again same for second, third so on days & find max of all
    
     
    
//     - Time complexity :  O(N^2)

// ### Approach2:

// - create 2 var, min = for find min value till current price for a stock, maxprofit
// - run a for loop, check if the value at i less than min
    
//     if prices[i] < min —> min = prices[i]
    
// - cal profit at current price, using current value and min value till now,
    
//     if its greater than max, max = profit
    
// - its a optimized approach for given problem

// - Time complexity : O(N)


#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int min = INT_MAX, maxprofit = 0;

    // for(int i = 0; i < prices.size(); i++){
    //     for(int j = i+1; j < prices.size(); j++){
    //         int diff = prices[j] - prices[i];
    //         if(diff > min)
    //             min = diff;
    //     }
    // }

    for(int i = 0; i < prices.size(); i++){
        if(prices[i] < min)
            min = prices[i];
        int profit = prices[i] - min;
        if(maxprofit < profit)
            maxprofit = profit;
    }
    return maxprofit;
}
