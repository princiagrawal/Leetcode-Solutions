class Solution {
public:

    bool isSafe(int row,int col,vector<string>&board,int n){
        int r=row,c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q'){
                return 0;
            }
            r--;
            c--;
        }
        r=row,c=col;
        while(c>=0){
            if(board[r][c]=='Q'){
                return 0;
            }
            c--;
        }
        r=row,c=col;
        while(r<n && c>=0){
            if(board[r][c]=='Q'){
                return 0;
            }
            r++;
            c--;
        }
        return 1;
    }

    void solve(vector<string>&board,int n,int &count,int col){
        if(col==n){
            count++;
            return ;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(board,n,count,col+1);
                board[row][col]='.';
            }
        }
    }

    int totalNQueens(int n) {//TC=O(n^2)
        int count=0;
        vector<string>board(n);
        string str(n,'.');
        for(int i=0;i<n;i++){
            board[i]=str;
        }
        solve(board,n,count,0);
        return count;
    }
};