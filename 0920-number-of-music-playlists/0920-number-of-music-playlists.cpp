class Solution {
public:
    #define ll long long
    const int mod=1e9+7;
   ll solve(int countSong,int uniqueSong,int n,int goal,int k,vector<vector<ll>>&dp){
        if(countSong==goal){
            if(uniqueSong==n){
                return dp[countSong][uniqueSong]=1;
            }
            return 0LL;
        }
        if(dp[countSong][uniqueSong]!=-1){
            return dp[countSong][uniqueSong];
        }
        ll result=0;
        if(n-uniqueSong>0){
            // pick unique song
            result+=(n-uniqueSong)*solve(countSong+1,uniqueSong+1,n,goal,k,dp);
        }
        if(uniqueSong-k>0){
            //replay a song
            result+=(uniqueSong-k)*solve(countSong+1,uniqueSong,n,goal,k,dp);
        }
        return dp[countSong][uniqueSong]=result%mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {//by codestorywithMIK
        //I have two choices...either to play a unique song or to replay a song
        vector<vector<ll>>dp(goal+1,vector<ll>(n+1,-1));
        return solve(0,0,n,goal,k,dp);
    }
};