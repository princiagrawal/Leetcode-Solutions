class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {//from editorial
        int n=nums.size();
        vector<int>ans;
/*// For each square, we will use the sum row + col as an identifier to the diagonal that it belongs to. We will use a hash map groups where groups[x] is a list of all values that appear in the diagonal with identifier x.
        int maxSize=0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
                maxSize=max(maxSize,i+j);
            }
        }
        for(int i=0;i<=maxSize;i++){// Each diagonal starting with sum 0 to sum maxKey.
            for(auto x=mp[i].rbegin();x!=mp[i].rend();x++){// print in reverse order.
                ans.push_back(*x);
            }
        }
        return ans;*/
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            ans.push_back(nums[r][c]);
            if(c==0 && r+1<n){
                q.push({r+1,c});
            }
            if(c+1<nums[r].size()){
                q.push({r,c+1});
            }
        }
        return ans;
    }
};