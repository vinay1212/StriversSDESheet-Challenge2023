// Approach 1:

// - we will find out all the permutations of the given combination, for this to be in sorted order, firstly sort the given array, before that save the current arrangement
// - now find out all the permutations using recursion, and store them, now find  the idx of current arrangement, and if it is last, then return first permutation
// - else return the next idx of current idx, as it will be next permutation
// - Time complexity : O(N!*N)
// - there is a inbuilt STL library function in C++,
//     - `next_permutation(a.begin(), a.end())`

// ### Approach 2:

// - above approach have huge time complexity, we need smaller time
// - to find the next permutation, we will need to keep some part of the array as it is,and by making some changes in right part find out next permutation
// - to decide what part we need to make changes, we will traverse the array from back, and find out the point at which current element is smaller than next element, as to make the next combination greater element than current is required
// - eg. arr = [2,1,5,4,3,0,0]
//     - here we cannot keep 2,1,5,4 as 3,0,0 can not make combination which will be greater than current, so its all comb will come before current
//     - we cannot keep 2,1,5 as 4,3,0,0 cannot make greater combo
//     - we cannot keep 2,1 as 5,4,3,0,0 cannot make greater combo
//     - but we can keep 2 as 1,5,4,3,0,0 multiple greater combinations are possible like, 3,4,5,1,0,0 and 4,5,1,3,0,0 and, 5,1,3,4,0,0
//     - but here we need just next combination, so it should be as smaller as possible, but greater than current one,
// - so we will start from back of the array & find out next bigger element than saved idx element, here its 3, which is just after 1, now swap(1,3)
// - it will look like [2,3,5,4,1,0,0]
// - now the 2,3 part is comes just after given permutation, now find out as smaller combo as possible, for that reverse the remaining array
// - we have found the next permutation



vector<int> nextGreaterPermutation(vector<int> &nums) {
    // Write your code here.
    int n = nums.size();
        int idx = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            reverse(nums.begin(), nums.end());
            return nums;
        }
        for(int i = n-1; i > idx; i--){
            if(nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }
        vector<int>temp;
        for(int i = idx+1; i < nums.size(); i++){
            temp.push_back(nums[i]);
        }
        reverse(temp.begin(), temp.end());
        for(int i = idx+1, j = 0; i < nums.size(); i++,j++){
            nums[i] = temp[j];
        }
        return nums;
}
