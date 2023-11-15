class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {//by codestorywithMIK
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i==0){
                arr[i]=1;
            }
            else{
                if(arr[i]-arr[i-1] > 1){
                    arr[i]=1+arr[i-1];
                }
            }
        }
        return arr[n-1];
    }
};