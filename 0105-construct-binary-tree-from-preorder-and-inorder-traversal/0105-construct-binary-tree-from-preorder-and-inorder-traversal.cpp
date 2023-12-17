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

    int preInd=0;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int s,int e){
        if(s>e){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[preInd]);
        int inInd=0;
        for(int i=s;i<=e;i++){
            if(preorder[preInd]==inorder[i]){
                inInd=i;
                break;
            }
        }
        preInd++;
        root->left=solve(preorder,inorder,s,inInd-1);
        root->right=solve(preorder,inorder,inInd+1,e);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return solve(preorder,inorder,0,n-1);
    }
};