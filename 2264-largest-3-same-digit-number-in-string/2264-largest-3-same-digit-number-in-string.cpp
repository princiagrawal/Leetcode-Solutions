class Solution {
public:
    string largestGoodInteger(string s) {
        int n=s.size();
        int maxi=-1;
        for(int i=1;i<n-1;i++){
            if(s[i]==s[i-1] && s[i]==s[i+1]){
                maxi=max(maxi,s[i]-'0');
            }
        }
        return (maxi==-1) ? "" : string(3,char(maxi+'0')); 
    }
};
// In the return statement, I use string(3, char(maxi + '0')) to create a string of length 3 where each character is the digit represented by maxi. This will return a string like "777" when maxi is 7.