class Solution {
public:
    int hIndex(vector<int>& citations) {//by codebix
        int n=citations.size();
        int l=0,h=n-1;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(citations[mid]>=n-mid){
                ans=n-mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};