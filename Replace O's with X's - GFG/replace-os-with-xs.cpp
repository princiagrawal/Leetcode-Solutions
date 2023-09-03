//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void dfs(int n,int m,vector<vector<char>>&mat,vector<vector<int>>&vis,int row,int col){
        vis[row][col]=1;
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && mat[nr][nc]=='O'){
                dfs(n,m,mat,vis,nr,nc);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !vis[i][0]){
                dfs(n,m,mat,vis,i,0);
            }
        }
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O' && !vis[0][j]){
                dfs(n,m,mat,vis,0,j);
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][m-1]=='O' && !vis[i][m-1]){
                dfs(n,m,mat,vis,i,m-1);
            }
        }
        for(int j=0;j<m;j++){
            if(mat[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n,m,mat,vis,n-1,j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && !vis[i][j]){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends