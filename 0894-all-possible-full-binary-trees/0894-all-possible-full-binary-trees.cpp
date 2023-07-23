/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<TreeNode*> solve(int n,vector<vector<TreeNode*>>&dp){
        if(n==1){
            TreeNode* newNode=new TreeNode(0);
            return {newNode};
        }
        if(n%2==0){
            return {};
        }
        if(dp[n].size()!=0){
            return dp[n];
        }
        vector<TreeNode*>ans;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*>left=solve(i,dp);
            vector<TreeNode*>right=solve(n-i-1,dp);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {//by pepcoding
        vector<vector<TreeNode*>>dp(n+1);
        return solve(n,dp);
    }
};