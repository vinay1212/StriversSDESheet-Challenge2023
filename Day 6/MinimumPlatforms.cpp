// ### Approach1 :

// - first sort the trains according to there departure timing.
// - for each train we will check how many overlapping trains exists.
// - for each train check if its arrival time is before the departure time of current train —> increase the count, check if its greater than max.

// - Time complexity : O( NlogN+N*N )
// - space complexity : O(1)

// ### Approach2 :

// - we will keep track of arrival and departure of trains,
// - create a vector pair, insert all arrival and departure times into it,  if entry is arrival mark it as arrival, same for departure
// - now sort this vector pair according to times, some special cases (guess)
// - now run a for loop on this vector pair, if it is arrival time increment count++, check if its greater than max, if its departure decrement count- -.

// - Time complexity : O( NlogN+N )
// - space complexity : O(N)



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
