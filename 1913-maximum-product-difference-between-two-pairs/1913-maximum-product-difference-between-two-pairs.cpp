class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int s1=INT_MAX,s2=INT_MAX,l1=INT_MIN,l2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>l1){
                l2=l1;
                l1=nums[i];
            }
            else if(nums[i]>l2){
                l2=nums[i];
            }
            if(nums[i]<s1){
                s2=s1;
                s1=nums[i];
            }
            else if(nums[i]<s2){
                s2=nums[i];
            }
        }
        return l1*l2-s1*s2;
    }
};