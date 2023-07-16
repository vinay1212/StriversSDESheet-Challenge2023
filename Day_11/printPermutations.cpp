// ### Approach 1 : Using extra space

// - we will declare ans vector of vectors to store the all permutations of input
// - we will use map and initialize it to zero to store freq of elements used in current permutation and call the recursive function, when the current element is used in permutation make its freq as 1
//     - when size of current permutation becomes equal to n(size of input) then it is a permutation and store that permutation in our ans, then return it
//     - run a for loop from 0 to n, for current element check if freq is unmarked, if yes —> it means the element is not included in current permutation yet, so insert into permutation & mark its freq as 1,
//     - call recursion again on current permutation after new element is added,
//     - when backtracking remove the last added element and change its freq back to unvisited(ie. 0)

// ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d17d1109-cf57-4794-9390-c554960429c6/Untitled.png)

// - Time complexity : O(N!*N)
// - space complexity : O(N)     —> using map to count freq.

// ### Approach2 : using backtracking & swapping

// - given  a nums array, we will declare vector of vector to return final ans
//     - whenever idx reaches to end of the array, consider the current state of nums as one of the permutations and insert it into ans
//     - start from current idx to last idx swap current element with everyone and call recursive function on next idx.
//     - while backtracking when you come back from recursion call re-swap back to original state,




#include <bits/stdc++.h> 

void fun(int idx, string s, string st, vector<string>&ans, vector<int> freq){
    if(st.size() == s.size()){
        ans.push_back(st);
        return;
    }

    for(int i = 0; i < s.size(); i++){
        if(freq[i] == 0){
            freq[i] = 1;
            st += s[i];
            fun(i, s, st, ans, freq);
            freq[i] = 0;
            st.pop_back();
        }
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    string st= "";
    vector<int>freq(s.size(), 0);
    fun(0, s, st, ans, freq);
    return ans;
}
