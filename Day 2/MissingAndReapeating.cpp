// ### Approach1:

// - create an array temp of size N, all initialize to 0.
// - traverse the given array, consider the element of given array as index and increment the index element by 1
// - start another for loop from i = 1 to n, check the elements in temp at i
//     - if element is 0 —> element i is missing from the given array.
//     - if element is 2 —> element i appears twice in given array.
    
//     - Time complexity : O(N)
//     - space complexity : O(N)
      
      

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 

	vector<int> v(n, 0);
	for(int i = 0;i < n; i++){
		v[arr[i]-1]++;
	}
	pair<int, int> p;
	for(int i = 0; i < n; i++){
		if(v[i] == 2)
			p.second = i+1;
		if(v[i] == 0)
			p.first = i+1;
	}
	return p;
	
}
