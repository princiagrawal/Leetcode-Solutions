class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {//self solved
        vector<int>ans;
        int n=nums.size();
        int sum=0,prefixSum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0;i<n;i++){
            int left=(nums[i]*i) - prefixSum;
            prefixSum+=nums[i];
            int right=abs((nums[i]*(n-i-1)) - (sum-prefixSum));
            // cout<<left<<" "<<right<<endl;
            ans.push_back(abs(left+right));
        }
        return ans;
    }
};