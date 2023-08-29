class Solution {
public:
    int bestClosingTime(string customers) {
        int x=customers.size();
        vector<int>n,y;
        int cn=0;
        n.push_back(0);
        y.push_back(0);
        for(int i=0;i<x;i++){
            if(customers[i]=='N'){
                cn++;
            }
            n.push_back(cn);
        }
        cn=0;
        for(int i=x-1;i>=0;i--){
            if(customers[i]=='Y'){
                cn++;
            }
            y.push_back(cn);
        }
        reverse(y.begin(),y.end());
        int ans=INT_MAX,ind=0;
        for(int i=0;i<=x;i++){
            int val=y[i]+n[i];
            if(val<ans){
                ans=val;
                ind=i;
            }
        }
        return ind;
    }
};
/*Here, the idea is to store the number of 'Y' and 'N' in a vector, let's call them vector y and n;
At any instance i the penalty depend on the sum of number of 'Y' remaining and the number of 'N' passed.
So, for that we'll be calculating the suffix sum of 'Y' and prefix sum of 'N' and storing them on vector y and n respectively. Then for each index the ans becomes
y[i]+n[i], and taking the minimum of all the indeces gives us the answer!
We'll be pushing 0 to y at end because at last no 'Y' will be left and similarly we'll do that for 'N' at initial stage as no 'N' have been passed.*/