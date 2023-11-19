class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=n-1;i>=1;i--){
            if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                ans+=(n-i);
            }
        }
        return ans;
    }
};