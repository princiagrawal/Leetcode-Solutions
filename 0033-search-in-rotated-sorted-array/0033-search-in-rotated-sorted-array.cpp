class Solution {
public:
    int search(vector<int>& nums, int target) {
        //by striver
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>=nums[l]){//left half is sorted
                if(target>=nums[l] && target<=nums[mid]){//target lies in left half
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{//right half is sorted
                if(target>=nums[mid] && target<=nums[h]){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
        }
        return -1;
    }
};