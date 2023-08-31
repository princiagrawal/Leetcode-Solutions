class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
         //by codestorywithMIK
         //similar to frog jump
        vector<int>startEnd(n+1,0);
        for(int i=0;i<ranges.size();i++){
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            startEnd[left]=max(startEnd[left],right);//make the vector
        }
        int taps=0,farthest=0,curr=0;
        for(int i=0;i<=n;i++){
            if(i>farthest){
                return -1;//agr wo margya toh
            }
            if(i>curr){
                curr=farthest;
                taps++;
            }
            farthest=max(farthest,startEnd[i]);
        }
        return taps;
    }
};