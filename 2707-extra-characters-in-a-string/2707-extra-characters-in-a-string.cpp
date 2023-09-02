class Solution {
public:
    unordered_set<string>st;

    int solve(string s,int ind,int n,vector<int>&dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int minExtra=INT_MAX;
        string currStr="";
        for(int i=ind;i<n;i++){
            currStr.push_back(s[i]);
            int currExtra=(st.find(currStr)==st.end()) ? currStr.length() : 0;
            int nextExtra=solve(s,i+1,n,dp);
            int totalExtra=currExtra+nextExtra;
            minExtra=min(minExtra,totalExtra);
        }
        return dp[ind]=minExtra;
    }

    int minExtraChar(string s, vector<string>& dictionary) {//by codestorywithMIK
        //using dp(TC=n^2)
        int n=s.length();
        for(auto word:dictionary){
            st.insert(word);
        }
        vector<int>dp(n+1,-1);
        return solve(s,0,n,dp);
    }
};