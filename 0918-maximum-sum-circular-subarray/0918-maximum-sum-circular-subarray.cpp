class Solution {
public:
   
    int minSumArr(vector<int>&nums,int n){
        int mini=INT_MAX,currSum=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            mini=min(mini,currSum);
            if(currSum>0){
                currSum=0;
            }
        }
        return mini;
    }

    int maxSumArr(vector<int>&nums,int n){
        int maxi=INT_MIN,currSum=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            maxi=max(maxi,currSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxi;
    }

    int maxSubarraySumCircular(vector<int>& nums) {//by code bashers
       int n=nums.size();
       int ans=INT_MIN;
       //Case 1-->if the whole array is negative
       int neg=1;
       for(int i=0;i<n;i++){
           if(nums[i]>0){
               neg=0;
               break;
           }
           ans=max(ans,nums[i]);
       }
       if(neg){
           return ans;
       }
       //Case 2-->if the maximum sum present in linear array
       int ans1=maxSumArr(nums,n);
       //Case 3-->if the maximum sum present in circular array
       int totalSum=0;
       for(int i=0;i<n;i++){
           totalSum+=nums[i];
       }
       int ans2=totalSum-minSumArr(nums,n);
       return max(ans1,ans2);
    }
};