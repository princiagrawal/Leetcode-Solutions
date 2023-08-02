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

    int maxi=0;

    void solve(TreeNode* root,int currLen,int prevDir){
        if(!root){
            return ;
        }
        maxi=max(maxi,currLen);
        if(prevDir==0){//mtlb ye left se aya h
            solve(root->left,1,0);
        }
        else{
            solve(root->left,currLen+1,0);
        }
        if(prevDir==1){//mtlb ye right se aya h
            solve(root->right,1,1);
        }
        else{
            solve(root->right,currLen+1,1);
        }
    }

    int longestZigZag(TreeNode* root) {//by aryan mittal in O(n)
        solve(root,0,0);
        solve(root,0,1);
        return maxi;
    }
};