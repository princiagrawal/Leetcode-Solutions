class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else if(i==0 && obstacleGrid[i][j]==0){
                    dp[i][j]=dp[i][j-1];
                }
                else if(j==0 && obstacleGrid[i][j]==0){
                    dp[i][j]=dp[i-1][j];
                }
                else if(obstacleGrid[i][j]==0){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
// Because you can only arrive to dp[1][1] from dp[0][1] or dp[1][0], you can only set one of them as 1 so that dp[1][1] can be 1, which means when you at the obstacleGrid[0][0], there are only 1 path.
//if there is a obstacle at (i,j), then dp[i][j] = 0.