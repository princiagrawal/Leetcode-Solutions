class Solution{
    public:

    double solve(int n, int k, int row, int col,vector<vector<vector<double>>>&dp){
        if(row<0 || col<0 || row>n-1  || col>n-1){
            return 0;
        }
        if(k==0){
            return 1;
        }
        if(dp[row][col][k]!=-1){
            return dp[row][col][k];
        }
        int dr[] = {-2,-1,1,2,2,1,-1,-2};
        int dc[] = {-1,-2,-2,-1,1,2,2,1};
        double possibility=0;
        for(int i=0;i<8;i++){
            possibility+=0.125 * solve(n,k-1,row+dr[i],col+dc[i],dp);
        }
        return dp[row][col][k]=possibility;
    }

    double knightProbability(int n, int k, int row, int col){
       vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));//[row][col][step]
       return solve(n,k,row,col,dp);
    }
};