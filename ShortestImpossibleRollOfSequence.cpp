#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        
        int n = rolls.size();
        
        unordered_set<int> st;
        int count = 0;

        for(int i = n - 1; i >= 0; i--){

            if(st.size() == k){
                count++;
                st.clear();
            }

            st.insert(rolls[i]);

        }

        if(st.size() == k){
                count++;
                st.clear();
            }

        return count + 1;


    }
};

int main() {
    
    return 0;
}