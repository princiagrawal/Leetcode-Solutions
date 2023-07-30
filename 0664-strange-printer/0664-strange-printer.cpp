class Solution {
public:

    int solve(int i,int j,string &s,vector<vector<int>>&dp,int n){
        if(i==j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int minMarks=INT_MAX;
        for(int k=i;k<j;k++){
            minMarks=min(minMarks,solve(i,k,s,dp,n)+solve(k+1,j,s,dp,n));
        }
        return s[i]==s[j] ? dp[i][j]=minMarks-1 : dp[i][j]=minMarks;
    }

    int strangePrinter(string s) {//by aryan mittal
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,s,dp,n);
    }
};