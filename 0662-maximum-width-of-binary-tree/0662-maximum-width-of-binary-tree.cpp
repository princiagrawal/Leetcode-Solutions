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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxi=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int x=q.size();
            int first,last;
            int startInd=q.front().second;//starting ind of first element in a level
            for(int i=0;i<x;i++){
                TreeNode* curr=q.front().first;
                int currInd=q.front().second - startInd;
                q.pop();
                if(i==0){//current level ke first node ki index
                    first=currInd;
                }
                if(i==x-1){//current level ke last node ki index
                    last=currInd;
                }
                if(curr->left){
                    q.push({curr->left,(long long)2*currInd+1});
                }
                if(curr->right){
                    q.push({curr->right,(long long)2*currInd+2});
                }
            }
            maxi=max(maxi,last-first+1);
        }
        return maxi;
    }
};