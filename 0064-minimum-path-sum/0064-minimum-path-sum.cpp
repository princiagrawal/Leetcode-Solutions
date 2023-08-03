class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                }
                else if(i==0){
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                }
                else if(j==0){
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                }
                else{
                    dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
// Create a dp array of same size as grid
// dp[0][0] = grid[0][0] , b'coz we are initially in this house
// dp[i][j] means minimum rent i need to pay to reach the house [i,j]
// for 0th row , there is only one way to reach any house, and that is by moving to right, therefore ,
// dp[0][i] = dp[0][i-1] + grid[0][i] (rent paid so far + rent for this house)
// for 0th column, there is only one way to reach any house, and that is by moving down, therefore,
// dp[i][0] = dp[i-1][0] + grid[i][0] (rent paid so far + rent for this house)
// And now for rest of the houses in the grid, say grid[i][j]
// * we can reach either from grid[i-1][j]
// * or from grid[i][j-1]
// * we will choose the one with minimum rent
// therefore, dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j]