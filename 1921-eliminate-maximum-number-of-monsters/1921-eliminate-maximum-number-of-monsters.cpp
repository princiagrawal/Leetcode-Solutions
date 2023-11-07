class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {//by CodeStoryWithMIK
        int n=dist.size();
        vector<double>time(n);
        for(int i=0;i<n;i++){
            time[i] = (double)((double)dist[i] / (double)speed[i]);
        }
        sort(time.begin(),time.end());
        int ans=0;
        double currTime=0.0;
        for(int i=0;i<n;i++){
            if(time[i]-currTime <= 0.0){
                return ans;
            }
            else{
                ans++;
            }
            currTime=currTime+1.0;
        }
        return ans;
    }
};