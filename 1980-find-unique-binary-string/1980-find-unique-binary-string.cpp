class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {//by codestorywithMIK
/*Approach-1 (Using simple conversion)
We no need to check from 0 to 65536. Only need to check from 0 to n
T.C : O(n^2) - Iterating on each string and converting each character to integer
S.C : O(n) - Using set
        unordered_set<int>st;
        for(auto it:nums){
            st.insert(stoi(it,0,2));
        }
        int n=nums.size();
        string ans="";
        for(int i=0;i<=n;i++){
            if(st.find(i)==st.end()){
                ans=bitset<16>(i).to_string();
                break;
            }
        }
        return ans.substr(16-n);*/


//Approach-3 (By discarding matching characters in each position)
//T.C : O(n)
//S.C : O(1)
        string ans="";
        for(int i=0;i<nums.size();i++){
            char currBit=nums[i][i];
            ans+=(currBit=='0') ? '1' : '0';
        }
        return ans;
    }
};