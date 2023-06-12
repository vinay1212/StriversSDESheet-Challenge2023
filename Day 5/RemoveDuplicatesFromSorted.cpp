int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.

	// set <int> s;
	// for(int i = 0; i < n; i++){
	// 	s.insert(arr[i]);
	// }
	// return s.size();

	int prev = arr[0];
	int cnt = 1;
	for(int i = 1; i < n; i++){
		if(arr[i] == prev)
			continue;
		else{
			prev = arr[i];
			cnt++;
		}
	}
	return cnt;
}
