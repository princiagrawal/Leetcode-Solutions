class Solution {
public:
    int hIndex(vector<int>& citations) {//by codebix using counting sort
        int n=citations.size();
        vector<int>bucket(n+1);
        for(auto it:citations){
            if(it>=n){
                bucket[n]++;
            }
            else{
                bucket[it]++;
            }
        }
        int sum=0;
        for(int i=n;i>=0;i--){
            sum+=bucket[i];
            if(sum>=i){
                return i;//greatest possible H-index
            }
        }
        return 0;
    }
};