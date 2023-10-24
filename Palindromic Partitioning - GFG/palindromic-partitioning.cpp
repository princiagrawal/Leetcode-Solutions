//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dp[500][500];

    bool isPalindrome(string &s,int l,int h){
        while(l<h){
            if(s[l++]!=s[h--]){
                return 0;
            }
        }
        return 1;
    }

    int solve(string &str,int s,int e){
        if(e==str.length()){
            return isPalindrome(str,s,e-1)?0:1e5;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int notPick=solve(str,s,e+1);
        int pick=1e9;
        if(isPalindrome(str,s,e)){
            pick=1+solve(str,e+1,e+1);
        }
        return dp[s][e]=min(pick,notPick);
    }

    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(str,0,0);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends