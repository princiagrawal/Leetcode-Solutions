class Solution {
public:

    bool dfs(vector<bool>&vis,vector<bool>&pathVis,vector<vector<int>>&adj,int node){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            //when the node is not visited
            if(!vis[it]){
                if(dfs(vis,pathVis,adj,it)){
                    return 1;
                }
            }
            //the node is already visited and its is on the same path
            else if(vis[it] && pathVis[it]){
                    return 1;
            }
        }
        pathVis[node]=0;
        return 0;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //using cycle detection by striver
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(numCourses);
        vector<bool>pathVis(numCourses);
        for(int i=0;i<numCourses;i++){
            if(dfs(vis,pathVis,adj,i)){//if there is a cycle
                return 0;
            }
        }
        return 1;
    }
};
//we can use topological sort or cycle detection