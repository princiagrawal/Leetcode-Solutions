class Solution {
public:
    int rob(vector<int>& nums) {//by code with alisha
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            if(dp[i-2]+nums[i] > dp[i-1]){//rob this current home
                dp[i]=dp[i-2]+nums[i];
            }
            else{//avoid this home
                dp[i]=dp[i-1];
            }
        }
        return dp[n-1];
//agr hm abhi current house i ko rob krenge toh mtlb ki hmne i-2 ko bhi rob kra hoga 
//agr hm abhi current house i ko rob nhii kr rhe mtlb hmne i-1 ko rob kia hoga toh hmne take aur not take wala case lgaakr whaan se max nikal liya h 
    }
};