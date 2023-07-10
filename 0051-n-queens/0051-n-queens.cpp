class Solution {
public:

void solve(int col,int n,vector<string>&board,vector<vector<string>>&ans,vector<int>&left,vector<int>&upperDia,vector<int>&lowerDia){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && upperDia[n-1+col-row]==0 && lowerDia[row+col]==0){//isSafe
                board[row][col]='Q';
                left[row]=1;
                upperDia[n-1+col-row]=1;
                lowerDia[row+col]=1;
                solve(col+1,n,board,ans,left,upperDia,lowerDia);
                board[row][col]='.';
                left[row]=0;
                upperDia[n-1+col-row]=0;
                lowerDia[row+col]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {//by striver optimized code
        vector<vector<string>>ans;
        vector<string>board(n);
        string str(n,'.');
        for(int i=0;i<n;i++){
            board[i]=str;
        }
        vector<int> left(n,0),upperDia((2*n-1),0),lowerDia((2*n-1),0);
        solve(0,n,board,ans,left,upperDia,lowerDia);
        return ans;
    }
};