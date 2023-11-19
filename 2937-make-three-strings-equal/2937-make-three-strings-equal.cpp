class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        int l=s3.length();
        int i=0;
        int size=min({n,m,l});
        int ans=0;
        while(i<size){
            if(s1[i]==s2[i] && s2[i]==s3[i]){
                i++;
            }
            else{
                break;
            }
        }
        if(i==0){
            return -1;
        }
        ans+=(n-i)+(m-i)+(l-i);
        return ans;
    }
};