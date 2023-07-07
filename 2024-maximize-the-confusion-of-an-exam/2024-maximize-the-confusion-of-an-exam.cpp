class Solution
{
    public:

        int solve(string s, int k, char ch)
        {
            int same=0,opp=0, maxi = 0;
            int left = 0, right = 0;
            int n = s.length();
            while (right < n) {
                if(s[right]==ch){
                    same++;
                }
                else{
                    opp++;
                }
                while(opp>k){
                    if(s[left]!=ch){
                        opp--;
                    }
                    left++;
                }
                maxi=max(maxi,right-left+1);
                right++;
            }
            return maxi;
        }

    int maxConsecutiveAnswers(string answerKey, int k)
    {
       	//same as longest substring of 1's with at most 1 0's
        int ans1 = solve(answerKey, k, 'T');
        int ans2 = solve(answerKey, k, 'F');
        return max(ans1,ans2);
    }
};