//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void solve(vector<int>&arr, int target,vector<int>&temp,vector<vector<int>>&ans,int ind,int n){
        if(ind==n || target==0){
            if(target==0){
                ans.push_back(temp);
            }
            return ;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1]){
                continue;
            }
            if(arr[i]>target){
                break;
            }
            temp.push_back(arr[i]);
            target-=arr[i];
            solve(arr,target,temp,ans,i+1,n);
            temp.pop_back();
            target+=arr[i];
        }
    }
  
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {//by striver
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        int n=candidates.size();
        solve(candidates,target,temp,ans,0,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends