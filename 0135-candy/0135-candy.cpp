class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        //by Ayushi Sharma using greedy approach
        vector<int>cand(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1] && cand[i]<=cand[i-1]){
                cand[i]=1+cand[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && cand[i]<=cand[i+1]){
                cand[i]=1+cand[i+1];
            }
        }
        int candies=0;
        for(int i=0;i<n;i++){
            candies+=cand[i];
        }
        return candies;
    }
};