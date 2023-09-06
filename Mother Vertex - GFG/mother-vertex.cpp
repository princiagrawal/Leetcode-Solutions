//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    
    void dfs(set<int>&st,int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(st.find(it)==st.end()){
                st.insert(it);
                dfs(st,it,vis,adj);
            }
        }
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    set<int>st;
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            st.insert(i);
	            dfs(st,i,vis,adj);
	            if(st.size()==V){
	                return i;
	            }
	            st.clear();
	        }
	    }
	    return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends