#include<bits/stdc++.h>
#include<vector>

using namespace std;

class DSU{
public:

    int mx;
    vector<int> par , size;

    DSU(int n){
        mx = 1;
        par.resize(n + 1);
        size.resize(n + 1 , 1);

        for(int j = 1 ; j <= n ; j++) par[j] = j;
    }

    int find(int x){
        return par[x] = (par[x] == x) ? x : find(par[x]);
    }

    void merge(int x , int y){

        int a = find(x);
        int b = find(y);

        if(a == b) return;

        if(size[a] > size[b]){
            size[a] += size[b];
            par[b] = a;
        }
        else{
            size[b] += size[a];
            par[a] = b;
        }

        mx = max({mx , size[a] , size[b]});

    }

};


class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        vector<pair<int , int>> v;
        for(int i = 0 ; i < n ; i++){
            v.push_back({nums[i] , i});
        }

        sort(v.begin() , v.end());

        DSU dsu(n);
        vector<bool> active(n + 1 , false);
        int k = 1;

        for(int j = n - 1 ; j >= 0 && k <= n;){
            double x = (double)threshold / k;

            while(j >= 0 && v[j].first > x){
                int idx = v[j].second;
                active[idx] = true;

                if(idx + 1 < n && active[idx+1]) dsu.merge(idx , idx + 1);
                if(idx - 1 >= 0 && active[idx-1]) dsu.merge(idx , idx - 1);

                j--;

            }

            if(j < n - 1 && dsu.mx >= k) return k;
            k++;

        }

        return -1;

    }
};

int main() {
    
    return 0;
}