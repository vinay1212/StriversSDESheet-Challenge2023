int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    // int l = 0, r = 0, i = 0, ans = 0;
    // if(m+n < k)
    //     return -1;
    // while(i < k){
    //     if(row1[l] <= row2[r]){
    //         ans = row1[l];
    //         l++;
    //         if(l == m){
    //             ans = row2[r+k-i-2];
    //             return ans;
    //         }
    //     }
    //     else{
    //         ans = row2[r];
    //         r++;
    //         if(r == n){
    //             ans = row1[l+k-i-2];
    //             return ans;
    //         }
    //     }
    //     // cout<< ans<<" ";
    //     i++;
    // }
    // return ans;

     if (m > n) 
    {
        return ninjaAndLadoos(row2, row1, n, m, k);
    }
  
    if (m == 0) 
    {
        return row2[k - 1];
    }
    
    // If k is equal to 1
    if (k == 1) 
    {
        return min(row1[0], row2[0]);
    }
  
    int i = min(m, k / 2);
    int j = min(n, k / 2);
    
    // If row1[i - 1] is greater than row2[j - 1]
    if (row1[i - 1] > row2[j - 1]) 
    {
        vector<int> newRow2;
        newRow2.assign(row2.begin() + j, row2.end());
        
        return ninjaAndLadoos(row1, newRow2, m, n - j, k - j);
    } 

    vector<int> newRow1;
    newRow1.assign(row1.begin() + i, row1.end());
        
    return ninjaAndLadoos(newRow1, row2, m - i, n, k - i);  
}
