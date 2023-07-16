// ### Approach 1:

// - we need to find the maximum possible minimum distance, so we will try from 1 to n, whether it is possible to place cows at distance 1, if yes then check for 2, check for 3, and so on until it is possible to place the cows at distance i, in this way when the condition fails, we will get the maximum possible minimum distance between any two cows.
// - the basic idea is min distance will always be between adjacent cows, so we will try to place adjacent cows apart by distance 1, then 2, then 3, and so on… and check till what distance is it possible to place these cows, when the condition fails we will get max distance possible.

// ![WhatsApp Image 2023-07-05 at 5.58.45 AM.jpeg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7a2b79c5-ccbc-4318-b803-1354129c985f/WhatsApp_Image_2023-07-05_at_5.58.45_AM.jpeg)

// - sort the given array, and we start from min distance as 1, and we keep increasing until placing the all cows in stalls is not possible anymore
// - like above for d = 4, placing cows is not possible,
//     - for dist d, checking if the cows can fit in stalls or not, we can simply iterate over our n stalls, if distance between last placed cow and current stall is greater than or equal to dist d, we place cow here, increment count of placed cows, and change last position of cow at current
// - after we are done , if no. of placed cows count greater than given aggressive cows, it means all cows can fit into stalls for dist d, return true.
// - Time complexity : O(N*M)   n = stalls, m = max distance

// ### Approach 2: binary search

// - we will use same method for check whether fitting of all cows is possible or not, just we will use binary search for finding max distance, we know min distance to check, it will be always 1, we know max distance possible, it will be distance between first and last stalls, between these min & max values apply binary search
// - here low will be always possible point & high will be impossible point, at some point these two will cross each other and loop will end, and they will change there polarity, so when they cross, high will change to possible point.
// - Time complexity : O(N*log(M))




#include <bits/stdc++.h> 
bool isPossible(vector<int>&stalls, int t, int k){
    int cnt = 1;
    int i = 1;
    int prev = stalls[0];
    while(i < stalls.size()){
        if(stalls[i]-prev >= t){
            cnt++;
    	    prev=stalls[i];
        }
        i++;
    }
        
    if(cnt >= k){
        return true;
    }
    return false;
}

int chessTournament(vector<int> stalls , int n ,  int k){
	// Write your code here

	sort(stalls.begin(), stalls.end());
        
        int mx = 0;
        int l = 1, r = stalls[n-1]-stalls[0];
        
        while(l <= r){
            int i = (l+r)/2;
            if(isPossible(stalls, i, k)){
                l = i+1;
            }
            else{
                r = i-1;
            }
            
        }
       
        return r;
}

