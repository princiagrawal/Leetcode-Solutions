/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

   void markParents(unordered_map<TreeNode*,TreeNode*>&parents,TreeNode* root){
       if(!root){
           return ;
       }
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
           TreeNode* curr=q.front();
           q.pop();
           if(curr->left){
               q.push(curr->left);
               parents[curr->left]=curr;
           }
           if(curr->right){
               q.push(curr->right);
               parents[curr->right]=curr;
           }
       }
   }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*,TreeNode*>parents;
        markParents(parents,root);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=1;
        int dist=0;
        while(!q.empty()){
            int x=q.size();
            if(dist==k){
                break;
            }
            dist++;
            for(int i=0;i<x;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=1;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=1;
                }
                if(parents[curr] && !vis[parents[curr]]){
                    q.push(parents[curr]);
                    vis[parents[curr]]=1;
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};