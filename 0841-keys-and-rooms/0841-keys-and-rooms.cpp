class Solution {
public:

    void dfs(vector<bool>&vis,int currRoom,vector<vector<int>>& rooms){
        vis[currRoom]=1;
        for(int i=0;i<rooms[currRoom].size();i++){
            if(!vis[rooms[currRoom][i]]){
                dfs(vis,rooms[currRoom][i],rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,0);
        dfs(vis,0,rooms);
        for(auto it:vis){
            if(it==0){
                return 0;
            }
        }
        return 1;
    }
};