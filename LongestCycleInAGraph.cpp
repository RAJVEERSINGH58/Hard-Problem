#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    int ans = -1;

    void dfs(int src, vector<bool>& vis, vector<int>& count, vector<bool>& inRec, vector<int>& edges) {
        
        if(src != -1){
            vis[src] = true;
            inRec[src] = true;

            int neigh = edges[src];

            if(neigh != -1 && ! vis[neigh]){
                count[neigh] = count[src] + 1;
                dfs(neigh , vis , count , inRec , edges);
            }
            else if(neigh != -1 && inRec[neigh]){
                ans = max(ans , count[src] - count[neigh] + 1);
            }

            inRec[src] = false;
        }

    }

    int longestCycle(vector<int>& edges) {

        int n = edges.size();

        vector<bool> vis(n, false);

        vector<int> count(n, 1);

        vector<bool> inRec(n, false);

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                dfs(i, vis, count, inRec, edges);
            }

        }

        return ans;
    }
};


int main() {
    
    return 0;
}