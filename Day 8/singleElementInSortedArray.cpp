int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	
	int l = 0, r = arr.size()-1;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }
        if(mid%2 == 1){
            if(arr[mid] == arr[mid+1])
                r = mid-1;
            else
                l = mid+1;
        }
        else{
            if(arr[mid] == arr[mid+1])
                l = mid+1;
            else
                r = mid-1;
        }

    }
    return 0;
}
