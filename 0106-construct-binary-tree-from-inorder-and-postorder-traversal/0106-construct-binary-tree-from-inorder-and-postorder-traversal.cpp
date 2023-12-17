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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int s,int e,int &postInd){
        if(s>e){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[postInd--]);
        int inInd=0;
        for(int i=s;i<=e;i++){
            if(root->val==inorder[i]){
                inInd=i;
                break;
            }
        }
        root->right=solve(postorder,inorder,inInd+1,e,postInd);
        root->left=solve(postorder,inorder,s,inInd-1,postInd);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int postInd=n-1;
        return solve(postorder,inorder,0,n-1,postInd);
    }
};