class Solution {
public:
    string getPermutation(int n, int k) {//by striver
       string ans="";
       int fact=1;
       vector<int>nums;
       for(int i=1;i<n;i++){
           fact*=i;
           nums.push_back(i);
       }
       nums.push_back(n);
       k=k-1;
       while(true){
           ans+=to_string(nums[k/fact]);
           //remove the number from nums that has been added to out ans
           nums.erase(nums.begin()+(k/fact));
           if(nums.size()==0){
               break;
           }
           k=k%fact;
           fact=fact/nums.size();
       }
       return ans;
    }
};