class SubrectangleQueries {
public:
vector<vector<int>>rec;
vector<vector<int>>subs;
    SubrectangleQueries(vector<vector<int>>& rectangle) {//optimised
        rec=rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        subs.push_back({row1,col1,row2,col2,newValue});
    }
    
    int getValue(int row, int col) {
        for(int i=subs.size()-1;i>=0;i--){
        if(row>=subs[i][0] && col>=subs[i][1] && row<=subs[i][2] && col<=subs[i][3]){
            return subs[i][4];
        }
        }
        return rec[row][col];
    }
};
//why we iterate the loop in getValue function from bottom to up?
// Lets suppose there is an entry which has been updated twice, So going from newest to oldest would return the latest value.
// We are looping from newest to oldest because we want the latest value in the rectangle at a particular position. If we don't do it this way then we would return old value which would have been overwritten during some later update.


/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */