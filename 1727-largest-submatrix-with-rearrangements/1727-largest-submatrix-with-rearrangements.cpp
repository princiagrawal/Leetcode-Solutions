class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    height[j]=0;
                }
                else{
                    height[j]+=1;
                }
            }
            vector<int>order_height=height;
            sort(order_height.begin(),order_height.end());
            for(int j=0;j<m;j++){
                ans=max(ans,order_height[j]*(m-j));
            }
        }
        return ans;
    }
};
// But, What if the largest rectangle doesn't form in the last row it ends in the second last row or before that??
// The first for loop is to go through every row...