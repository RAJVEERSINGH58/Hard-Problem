#include<bits/stdc++.h>
#include<vector>

using namespace std;

typedef pair<int , int> pp;
class Solution {
public:

    int m , n;

    bool isSafe(int i , int j){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        
        m = heightMap.size();
        n = heightMap[0].size();

        priority_queue<pair<int , pp> , vector<pair<int , pp>> , greater<pair<int , pp>> > pq;

        int maxr = m - 1 , minr = 0 , minc = 0 , maxc = n - 1;
        vector<vector<bool>> vis(m , vector<bool>(n , false));

        for(int i = 0 ; i < m ; i++){
            pq.push({heightMap[i][0] , {i , 0}});
            pq.push({heightMap[i][n-1] , {i , n-1}});
            vis[i][0] = true;
            vis[i][n-1] = true;
        }

        for(int i = 1 ; i < n - 1 ; i++){
            pq.push({heightMap[0][i] , {0 , i}});
            pq.push({heightMap[m-1][i] , {m-1 , i}});
            vis[0][i] = true;
            vis[m-1][i] = true;
        }

        vector<int> dx = {0 , 1 , 0 , -1};
        vector<int> dy = {1 , 0 , -1 , 0};

        int water = 0;

        while(! pq.empty()){

            auto x = pq.top();
            pq.pop();

            int h = x.first;
            int i = x.second.first;
            int j = x.second.second;

            for(int k = 0 ; k < 4 ; k++){

                int i_ = i + dx[k];
                int j_ = j + dy[k];

                if(isSafe(i_ , j_) && ! vis[i_][j_]){

                    water += max(h - heightMap[i_][j_] , 0);
                    pq.push({max(h , heightMap[i_][j_]) , {i_ , j_}});
                    vis[i_][j_] = true;

                }

            }

        }
        return water;

    }
};

int main() {
    
    return 0;
}