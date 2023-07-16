vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    map<int, int>mp;
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }
    priority_queue<pair<int, int>>pq;
    for(auto it:mp){
        pair<int, int>p;
        p.first = it.second;
        p.second = it.first;
        pq.push(p);
    }
    int count = 0;

    while(count<k){
        count++;
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
