#include<bits/stdc++.h>
// vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
// {
// 	// Write your code here.
// 	priority_queue<int> pq;
// 	priority_queue<int, vector<int>, greater<int>> st;
// 	for(int i = 0; i < n; i++){
// 		pq.push(arr[i]);
// 		st.push(arr[i]);
// 	}
// 	vector<int> ans;
// 	int i = 1;
// 	int t = 1;
// 	while(t < k){
// 		pq.pop();
// 		st.pop();
// 		t++;
// 	}
// 	ans.push_back(st.top());
// 	ans.push_back(pq.top());
// 	return ans;
// }


int partition(vector<int> &arr, int left, int right, int pivotIndex) 
{
    int pivotValue = arr[pivotIndex];    
    swap(arr[pivotIndex], arr[right]); 
    int current = left;
    
    for(int i = left; i < right; i++) {
        if(arr[i] < pivotValue) {
            swap(arr[current], arr[i]);
            current++;
        }
    }
    swap(arr[right], arr[current]);
    return current;
}

int quickSelect(vector<int> &arr, int left, int right, int k) 
{
    if(left == right){
        return arr[left];
    }
    int pivotIndex = left + rand() % (right-left+1);
    
    int partitionIndex = partition(arr, left, right, pivotIndex);

    if(partitionIndex >= k)
    {
        return quickSelect(arr, left, partitionIndex-1, k);
    }
    
    if(partitionIndex < k-1)
    {
        return quickSelect(arr, partitionIndex+1, right, k);
    }

    return arr[partitionIndex];
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> result(2);
    result[0] = quickSelect(arr, 0, n-1, k);    
    result[1] = quickSelect(arr, 0, n-1, n-k+1);

    return result;
}
