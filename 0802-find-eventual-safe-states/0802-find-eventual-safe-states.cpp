class Solution {
public:

    bool dfs(int node,vector<bool>&vis,vector<bool>&pathVis,vector<vector<int>>& graph,vector<bool>&check){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        for(auto it:graph[node]){
            if(vis[it]==0){
                if(dfs(it,vis,pathVis,graph,check)==1){
                    check[it]=0;
                    return 1;
                }
            }
            else if(vis[it]==1 && pathVis[it]==1){
                check[it]=0;
                return 1;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return 0;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<bool> vis(v,0);
        vector<bool> pathVis(v,0);
        vector<bool> check(v,0);//so that the answers could be in ascending order
        vector<int>safeNodes;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,graph,check);
            }
        }
        for(int i=0;i<v;i++){
            if(check[i]==1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
//anyone who is a part of cycle can never be a safe node
//anyone who leads to a cycle can never be a safe node