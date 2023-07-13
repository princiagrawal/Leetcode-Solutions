class Solution {
public:

    //function to check for cycle
    bool dfs(int node,vector<bool>&vis,vector<bool>&pathVis,stack<int>&st,vector<vector<int>>&adj){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,st,adj)==0){
//if cycle is present return false , which means stack will never have the cyclic nodes.
                    return 0;
                }
            }
            else if(vis[it] && pathVis[it]){
                return 0;//there is a cycle
            }
        }
        st.push(node);
        pathVis[node]=0;
        return 1;//the graph is not cyclic
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //using cycle detection by striver
        vector<int>ans;
        vector<bool>vis(numCourses,0);
        vector<bool>pathVis(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        stack<int>st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,st,adj);
            }
        }
//stack doesnt have all nodes , i.e. cyclic graph -> means return the empty vector
        if (st.size() != numCourses) 
            return ans;

        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans ;
    }
};