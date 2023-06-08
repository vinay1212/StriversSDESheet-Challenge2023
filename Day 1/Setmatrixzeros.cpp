//- using set(row,col), traverse the matrix, if element is zero, insert its indexes  i,  j into the sets.
//- basically storing the rows & cols having value 0,
//- traverse matrix, if any of its index exists in sets, ie. i in rows || j in cols→ make the element 0.
//- Time complexity : O(N*M)
//- space complexity : O(2*no. of zeros)

//The time complexity of set.find( key ) is O( log N ). As the elements are stored in a sorted manner by default.



#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	set<int>r;
	set<int>c;
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[0].size(); j++){
			if(matrix[i][j] == 0){
				r.insert(i);
				c.insert(j);
			}
		}
	}
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[0].size(); j++){
			if(r.find(i) != r.end() || c.find(j) != c.end()){
				matrix[i][j] = 0;
			}
		}
	}
}
