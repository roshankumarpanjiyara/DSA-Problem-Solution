#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    // int count = 0;
    // for(int i = 0;i<a.size();i++){
    //     int x = 0;
    //     for(int j = i;j<a.size();j++){
    //         x ^= a[j];
    //         if(x == b){
    //             count++;
    //         }
    //     }
    // }

    // return count;

    unordered_map<int, int> mp;
    int count = 0;
    int xr = 0;

    for(int i = 0;i<a.size();i++){
        xr ^= a[i];

        if(xr == b){
            count++;
        }

        if(mp.find(xr^b) != mp.end()){
            count += mp[xr^b];
        }

        mp[xr]++;
    }

    return count;
}
