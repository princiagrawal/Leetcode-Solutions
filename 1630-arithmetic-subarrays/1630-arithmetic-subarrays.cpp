class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        //by codestorywithMIK
        
        //Brute Force
        /*vector<bool>ans;
        int n=nums.size();
        for(int i=0;i<l.size();i++){
            vector<int>arr(nums.begin()+l[i],nums.begin()+r[i]+1);
            sort(arr.begin(),arr.end());
            int diff=arr[1]-arr[0];
            for(int j=2;j<arr.size();j++){
                if(arr[j]-arr[j-1]!=diff){
                    ans.push_back(false);
                    break;
                }
            }
            // If the loop completes without breaking, it means it's a valid arithmetic subarray
            if (ans.size() == i) {
                ans.push_back(true);
            }
        }
        return ans;*/
        int n=nums.size();
        vector<bool>ans;
        //using An=A+(n-1)d
        for(int i=0;i<l.size();i++){
            vector<int>arr(nums.begin()+l[i],nums.begin()+r[i]+1);
            int mini=INT_MAX,maxi=INT_MIN;
            unordered_set<int>st;
            for(int j=0;j<arr.size();j++){
                mini=min(mini,arr[j]);
                maxi=max(maxi,arr[j]);
                st.insert(arr[j]);
            }
            if ((maxi - mini) % (arr.size() - 1) != 0) {
                ans.push_back(false);
            } 
            else {
                int d = (maxi - mini) / (arr.size() - 1);
                int curr = mini + d;
                while (curr < maxi) {
                    if (st.find(curr) == st.end()) {
                        ans.push_back(false);
                        break;
                    }
                    curr += d;  // curr, curr+d, curr+2d, curr+3d.........
                }
                if (curr >= maxi) {
                    ans.push_back(true);
                }
            }
        }
        return ans;
    }
};