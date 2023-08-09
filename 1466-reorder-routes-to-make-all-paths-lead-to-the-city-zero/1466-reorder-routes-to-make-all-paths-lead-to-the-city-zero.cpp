class Solution {
public:
int count=0;

    void dfs(int n,unordered_map<int,vector<pair<int,int>>>&adj,int node,vector<bool>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                if(it.second==1){//reorder the path
                    count++;
                }
                dfs(n,adj,it.first,vis);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {//by codestorywithMIK
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});//ise bidirectional krdo
        }
        vector<bool>vis(n,0);
        dfs(n,adj,0,vis);
        return count;
    }
};
        //Hum routes ko bidirectional bana rahe hai
        //1 weight for asli route
        //0 weight for nakli route
        //dfs traversal karenge 
        //agar u->v hum asli route se jaa paa rahe hai matlab v->u hume nakli route se aana padega
        //Hence uss route ko flip karna hoga