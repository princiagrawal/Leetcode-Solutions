class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //by code with alisha
        int n=nums.size();
        if(n<3){
            return 0;
        }
        int left=INT_MAX,mid=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>mid){
                return 1;
            }
            else if(nums[i]<left){
                left=nums[i];
            }
            else if(nums[i]>left && nums[i]<mid){
                mid=nums[i];
            }
        }
        return 0;
    }
};
