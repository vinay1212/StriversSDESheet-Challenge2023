// Approach1 :

// - combine these two arrrays into some third arrays, sort it, then find median
// - ie. if total element are odd, select middle element
// - if total elements are even, take avg of two middle elements
// - Time complexity : O((N+M)log(N+M))
// - space complexity : O(N+M)

// Approach2 :

// - we can notice that we don’t want the entire arrays, we just want the middle elements of arrays, so instead of using third array, we can use 2 pointers, and increment there position until half of elements are left behind
// - for shifting these 2 elements, we will use method of combining 2 sorted arrays
// - take 2 pointers, each at starting of 2 arrays
// - increment them until total count is reached half
// - return median considering even or odd total numbers
// - Time complexity : O(N+M)
// - space complexity : O(1)

// Approach3 :

// - here the 2 arrays are sorted, and we will use this to our benefit, we can simply apply binary search here
// - we will try to partition these arrays into half, such that half elements combined of both are on left, and rest on right
// - condition for the partition is simple, left partition should contains all elements smaller than right elements
// - it means l1 < r2  && l2 < r1, if this is not true, we will try binary searching for right combination
// - firstly find out & make first array as smaller, use 2 pointers on it, low & high, apply condition low ≤ high
//     - find the middle of it, consider it as cut1, then count cut2 elements by subtracting cut1 elements from total no. before median
//     - check if left half of partition has half no. of elements, then check if partition is valid  ie. l1<=r2 and l2<=r1
//         - if yes, if total size is even take avg of top 2 elements of left partition
//         - if size is odd, return the max of left partition
//     - else try shifting, low & high, to validate the partition
// - Time complexity : O(log(N,M))
// - space complexity : O(1)




#include <bits/stdc++.h>

double median(vector<int>& a, vector<int>& b) {
	if(b.size() < a.size())
		return median(b,a);
	
	int n1 = a.size();
	int n2 = b.size();

	int l = 0, h = a.size();

	while(l <= h){
		int cut1 = (l+h)/2;
		int cut2 = (n1+n2+1)/2 - cut1;

		int l1 = (cut1 == 0 ? INT_MIN : a[cut1-1]);
		int l2 = (cut2 == 0 ? INT_MIN : b[cut2-1]);

		int r1 = (cut1 == n1 ? INT_MAX : a[cut1]);
		int r2 = (cut2 == n2 ? INT_MAX : b[cut2]);

		if(l1 <= r2 && l2 <= r1){
			if((n1+n2)%2 == 0){
				// cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;
				return ((max(l1, l2) + min(r1, r2))/2.0);
			}
			else{
				return 1.0*max(l1,l2);
			}
		}
		else if(l1 > r2){
			h = cut1-1;
		}
		else{
			l = cut1+1;
		}
	}

	return 0.0;

}
