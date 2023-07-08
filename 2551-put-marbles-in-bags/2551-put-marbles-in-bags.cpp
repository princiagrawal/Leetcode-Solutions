class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {//by aryan mittal
        int n=weights.size();
        vector<int>consSum;
        for(int i=0;i<n-1;i++){
            consSum.push_back(weights[i]+weights[i+1]);
        }
        sort(consSum.begin(),consSum.end());
        long long minSum=0,maxSum=0;
        for(int i=0;i<k-1;i++){
            minSum+=consSum[i];
            maxSum+=consSum[n-i-2];
        }
        return maxSum-minSum;
    }
};