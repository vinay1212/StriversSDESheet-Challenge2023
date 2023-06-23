// ### Approach 1 : Naive approach

// - Here in naive approach we will check for all the possible unique substrings of the given string
// - and compare there size, whichever has the max size, we will return it
// - so, to check for every possible substring without repeating characters, we will use map
// - we will iterate a for loop, current element will consider as starting index of substring, and iterate from current index till the elements are unique, and store its length,
// - to check if sub-string traversed till now is unique, we will insert its elements into map, if count of element is already 1, then we have found the duplicate element, this is the max size of current substring, break it
// - Time complexity : O(N*N)
// - Space Complexity : O(logN)

// ### Approach 2 : Optimized approach

// - the above solution is of O(N*N), we need better solution
// - we will use sliding window concept, take 2 pointers, l & r, starting both at zero
// - we will maintain the unique substring between l & r at any point of time
// - for checking if the elements in substring are unique we will use set
// - run a while loop till r reaches the end of string
//     - check if current r element exists in set
//         - if it does not, then insert the current element r into set, and find out length of substring till now (ie. r-l+1), check if its greater than max, increment right to next
//         - if it exists, then we need remove this element from the substring, for this remove the char at l from string, by removing element at l from set & incrementing l pointer (In this way eventually duplicate element will get deleted from substring)(goto staring of while loop)
// - Time complexity : O(N)
// - Space Complexity : O(K) (unique element)



#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here

    int mx = 0, i = 0;
    // for(i = 0; i < input.size(); i++){
    //     vector<int>mp(26,0);
    //     int count = 0, j = i;
    //     while(j < input.size()){
    //         if(mp[input[j]-'a'] == 1){
    //             break;
    //         }
    //         count++;
    //         mp[input[j]-'a'] = 1;
    //         j++;
    //     }
    //     mp.clear();
    //     mx = max(mx, count);
    // }
    // return mx;

    int l = 0, r = 0;
    set<char> s;

    while(r < input.size()){
        if(s.find(input[r]) == s.end()){
            int len = r-l+1;
            s.insert(input[r]);
            mx = max(mx, len);
            r++;
        }
        else{
            char ch = input[l];
            s.erase(ch);
            l++;
        }

    }
    return mx;
}
