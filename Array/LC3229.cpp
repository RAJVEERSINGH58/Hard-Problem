#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        
        int n = nums.size();
        vector<int> diff(n);

        for(int i = 0 ; i < n ; i++) diff[i] = nums[i] - target[i];

        long long op = abs(diff[0]);
        int prev = diff[0];

        for(int i = 1 ; i < n ; i++){

            int curr = diff[i];

            if(curr > 0 && prev < 0){
                op += abs(curr);
            }
            else if(curr < 0 && prev > 0){
                op += abs(curr);
            }
            else{

                if(abs(prev) < abs(curr)){
                    op += abs(curr) - abs(prev);
                }

            }

            prev = curr;


        }

        return op;

    }
};

int main() {
    
    return 0;
}