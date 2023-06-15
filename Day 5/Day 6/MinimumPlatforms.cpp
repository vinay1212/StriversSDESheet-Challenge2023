bool sortcol(const pair<int,int> &v1, const pair<int,int> &v2){
    if(v1.first == v2.first){
        if(v1.second == 'a' && v2.second == 'd')
            return true;
    }
    else if(v1.first < v2.first)
        return true;
    return false;
}
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        v.push_back({at[i], 'a'});
        v.push_back({dt[i], 'd'});
    }
    sort(v.begin(), v.end(), sortcol);

    
    int mx = 0, count = 0;

    for(int i = 0; i < v.size(); i++){
        if(v[i].second == 'a'){
            count++;
            mx = max(mx, count);
        }
        else{
            count--;
        }
    }
    return mx;
}
