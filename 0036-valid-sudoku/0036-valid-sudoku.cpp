class Solution {
public:
    
    bool isValid(int row,int col,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(i!=row){
                if(board[i][col]==board[row][col]){
                    return 0;
                }
            }
        }
        for(int j=0;j<9;j++){
            if(j!=col){
                if(board[row][j]==board[row][col]){
                    return 0;
                }
            }
        }
        int r=(row/3)*3;
        int c=(col/3)*3;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(i!=row && j!=col){
                    if(board[i][j]==board[row][col]){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string>st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isValid(i,j,board)){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};