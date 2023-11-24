class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //understand from the example no. 3
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int ans=0;
        for(int i=n/3;i<n;i+=2){
            ans+=piles[i];
        }
        return ans;
    }
};