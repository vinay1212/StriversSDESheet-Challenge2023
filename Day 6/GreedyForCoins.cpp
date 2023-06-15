// - we will start by the largest coins, and move the next smaller coin if required target is smaller than current coin
// - run a while loop, until the required amount is not equal to zero
//     - inside run another while loop, till required amount is greater than equal to current coin
//         - decrement the amount by coin, increase the count by 1
//     - when it comes out of loop, it means current coin is greater than required amount, shift to next smaller coin




#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int>den = {1,2,5,10,20,50,100,500,1000};
    int j = 8;
    int count = 0;
    while(amount != 0){
        while(amount >= den[j]){
            amount -= den[j];
            count++;
        }
        j--;
    }
    return count;
}
