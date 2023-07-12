//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    bool isSafe(bool graph[101][101], int m, int n,int color[],int col,int node){
        for(int k=0;k<n;k++){
            if(k!=node && graph[k][node]==1 && color[k]==col){
                return 0;
            }
        }
        return 1;
    }

    bool solve(bool graph[101][101], int m, int n,int color[],int node){
        if(node==n){
            return 1;
        }
        for(int i=1;i<=m;i++){//try all colors
            if(isSafe(graph,m,n,color,i,node)){//if this node can be colored with this color
                color[node]=i;//color this node with this color
                if(solve(graph,m,n,color,node+1)){
                    return 1;
                }
                color[node]=0;
            }
        }
        return 0;//no color was able to color it
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {//by striver
        int color[n];
        return solve(graph,m,n,color,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends