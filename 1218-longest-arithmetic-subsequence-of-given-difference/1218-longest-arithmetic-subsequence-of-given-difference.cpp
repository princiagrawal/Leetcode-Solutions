class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {//by aryan mittal
    //it is giving TLE
        int n=arr.size();
        unordered_map<int,int>dp;
        int maxi=1;
        for(auto it:arr){
            maxi=max(maxi,dp[it]=1+dp[it-difference]);
        }
        return maxi;
    }
};