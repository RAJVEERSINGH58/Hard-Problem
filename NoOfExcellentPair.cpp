#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    int setBit(int n){
        int count = 0;
        while(n > 0){
            n = n & (n - 1);
            count++;
        }
        return count;
    }

    int lowerBound(vector<int>& bits , int x){

        int n = bits.size();
        int lo = 0;
        int hi = n - 1;

        int ans = n;

        while(lo <= hi){

            int mid = lo + (hi - lo) / 2;

            if(bits[mid] >= x){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1; 

        }

        return ans;

    }

    long long countExcellentPairs(vector<int>& nums, int k) {
        

        unordered_set<int> st(nums.begin() , nums.end());
        vector<int> bits;

        long long ans = 0;

        for(int x : st) bits.push_back(setBit(x));

        sort(bits.begin() , bits.end());

        int n = bits.size();
        
        for(int i = 0 ; i < n ; i++){

            int req = k - bits[i];

            int j = lowerBound(bits , req);

            ans += n - j;


        }

        return ans;

    }
};

int main() {
    
    return 0;
}