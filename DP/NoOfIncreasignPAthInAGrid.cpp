#include<bits/stdc++.h>
#include<vector>

using namespace std;

#define MOD 1000000007
class Solution {
public:

    int m , n;
    vector<vector<bool>> vis;
    vector<int> dx = {1 , 0 , -1 , 0};
    vector<int> dy = {0 , 1 , 0 , -1};

    vector<vector<long long>> dp;

    bool isSafe(int i , int j){
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    long long solve(vector<vector<int>>& grid , int i , int j){

        long long ans = 1;

        if(dp[i][j] != -1) return dp[i][j];

        for(int k = 0 ; k < 4 ; k++){
            int i_ = i + dx[k];
            int j_ = j + dy[k];

            if(isSafe(i_ , j_) && grid[i_][j_] > grid[i][j] && ! vis[i_][j_]){
                vis[i_][j_] = true;

                ans = (ans % MOD + solve(grid , i_ , j_) % MOD) % MOD;

                vis[i_][j_] = false;

            }

        }

        return dp[i][j] = ans % MOD;



    }

    int countPaths(vector<vector<int>>& grid) {
        
        long long ans = 0;
        m = grid.size();
        n = grid[0].size();

        dp.clear();
        dp.resize(m , vector<long long>(n , -1));

        vis.clear();
        vis.resize(m , vector<bool>(n , false));

        for(int i = 0 ; i < m ; i++){

            for(int j = 0 ; j < n ; j++){
                vis[i][j] = true;

                ans = (ans % MOD +  solve(grid , i , j) % MOD) % MOD;

                vis[i][j] = false;
            }

        }

        return ans;

    }
};

int main() {
    
    return 0;
}