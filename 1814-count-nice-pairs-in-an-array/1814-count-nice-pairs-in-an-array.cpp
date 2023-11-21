class Solution {
public:

    int rev(int n){
        int temp=0;
        while(n>0){
            temp=temp*10+(n%10);
            n/=10;
        }
        return temp;
    }

    int countNicePairs(vector<int>& nums) {//by codestorywithMIK
        int n=nums.size();
        long long mod=1e9+7;
        unordered_map<long long,long long>mp;
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=((ans%mod)+(mp[nums[i]-rev(nums[i])]++)%mod)%mod;
        }
        return ans;
    }
};