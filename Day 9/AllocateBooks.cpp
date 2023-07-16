// ### Approach 1:

// - here we have definite search space, as pages are limited, we will do a linear search from low to high, for each no. we will check whether using this limit of pages, 
// how many student we can assign books to, at starting limit will be low, so no. of students to whom books are allocated will be more, then as the limit increases no. of students allocated will become less, 
// between max and min limit there exists out ans, we have return minimum of it.
// - lower boundary of search space will be max pages among all the books(as all students needs to allocated atleast one book), upper boundary of search space will be sum of all books, 
// if all book are assigned to one student(although its not allowed)
// - now while searching for correct limit in range, we will consider current pointer as max number of pages that can be assigned to each student, and assign all given books according to this, & check is it valid ,
//     - if sum of pages exceeds current limit for first student, we will assign rest of books to second, if for second also exceed, assign remaining to third student and so on.
//     - now to check validity, if no. of student we assigned books to exceeds given student limit, it means allocation is invalid, we need to allow more pages to each student, 
// it means we need to shift mid to right side( l=mid+1)
//     - but if it is valid, no. students to whom the books are assigned is less than limit, it means allocation is valid, but we need to optimize it further as we want the max pages allocation to each student
// as minimum as possible, shift mid to left side (r = mid-1), but before that update the result that current mid is possible ans
// - Time complexity : O((MX-MN)*N)

// Approach2 : binary search 

// - its a binary search problem, it might not appear first, first approach is using recursion and finding all possible allocations, then find the min one, but again recursion will have exponential time complexity
// - we will use binary search for this, firstly we will set a search space for allocation of pages, min & max number of pages that can be assigned to student,
// - Time complexity : O(N)




#include <bits/stdc++.h> 
bool isValid(long long mid, long long n, long long m, vector<int>&time){
	long long days = 1;
	long long chapters = 0;

	for(long long i = 0; i < m; i++){
		chapters += time[i];

		if(chapters > mid){
			days++;
			chapters = time[i];
		}
	}

	if(days > n)
		return false;
	return true;

}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	
	long long l = 0, r = 0;
	for(long long i = 0; i < m; i++){
		r += time[i];
		l = max(l, 1LL*time[i]);
	}
	long long result = -1;

	while(l <= r){
		long long mid = l+(r-l)/2;

		if(isValid(mid, n, m, time) == true){
			result = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	return result;
}
