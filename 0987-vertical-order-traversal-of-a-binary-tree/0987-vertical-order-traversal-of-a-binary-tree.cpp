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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;

        if(!root){
            return ans;
        }

        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>mp;

        q.push({root,{0,0}});

        while(!q.empty()){
            TreeNode* curr=q.front().first;
            int ver=q.front().second.first;
            int lev=q.front().second.second;
            q.pop();
            mp[ver][lev].insert(curr->val);
            if(curr->left){
                q.push({curr->left,{ver-1,lev+1}});
            }
            if(curr->right){
                q.push({curr->right,{ver+1,lev+1}});
            }
        }
        for(auto it:mp){
            vector<int>col;
            for(auto x:it.second){
                col.insert(col.end(),x.second.begin(),x.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};