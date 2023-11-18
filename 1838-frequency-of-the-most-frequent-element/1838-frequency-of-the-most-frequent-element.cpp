class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0,right=0;
        long currSum=0;
        int maxi=0;
        while(right<n){
            currSum+=nums[right];
            if(((long)nums[right]*(right-left+1))-currSum > k){
                currSum-=nums[left];
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;

        }
        return maxi;
    }
};