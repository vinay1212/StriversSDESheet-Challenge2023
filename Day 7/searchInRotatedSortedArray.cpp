int search(int* arr, int n, int key) {
    // Write your code here.

    int l = 0, r = n-1;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[l] <= arr[mid]){
            if(key <= arr[mid] && key >= arr[l])
                r = mid-1;
            else
                l = mid+1;
        }
        else{
            if(key >= arr[mid] && key <= arr[r])
                l = mid+1;
            else
                r = mid-1;
        }

    }
    return -1;
}
