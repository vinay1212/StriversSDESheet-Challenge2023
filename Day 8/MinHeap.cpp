#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.

    vector<int>pq;
    vector<int> ans;
    for(int i = 0; i < q.size(); i++){
        int t = q[i].size();
        if(t == 1){
            int mx = INT_MAX, idx = -1;
            for(int i = 0; i < pq.size(); i++){
                if(pq[i]<mx){
                    mx = pq[i];
                    idx = i;
                }
            }
            // cout<<"mx "<<mx<<" idx "<<idx<<endl;
            ans.push_back(mx);
            pq.erase(pq.begin()+idx);
        }
        else{
            pq.push_back(q[i][1]);
        }
    }
    return ans;
}
