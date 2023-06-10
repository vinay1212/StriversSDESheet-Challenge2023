#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.

    // map<int, int>mp;
    // for(int i = 0; i < arr.size(); i++){
    //     mp[arr[i]]++;
    // }
    // vector<int>v;
    // for(auto it: mp){
    //     if(it.second > arr.size()/3){
    //         v.push_back(it.first);
    //     }
    // }
    // return v;

    int firstmaj, secondmaj, firstcnt = 0, secondcnt = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == firstmaj){
            firstcnt++;
        }
        else if(arr[i] == secondmaj){
            secondcnt++;
        }
        else if(firstcnt == 0){
            firstmaj = arr[i];
            firstcnt++;
        }
        else if(secondcnt == 0){
            secondmaj = arr[i];
            secondcnt++;
        }
        else{
            firstcnt--;
            secondcnt--;
        }

    }
    vector<int>ans;
    int f = 0, s = 0;
    // cout<<firstmaj<<" "<<secondmaj<<endl;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == firstmaj)
            f++;
        else if(arr[i] == secondmaj)
            s++;
    }
    if(f>arr.size()/3)
        ans.push_back(firstmaj);
    if(s > arr.size()/3)
        ans.push_back(secondmaj);
    return ans;

}
