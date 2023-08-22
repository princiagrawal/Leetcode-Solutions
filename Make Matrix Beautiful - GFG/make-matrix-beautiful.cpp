//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>>m, int n)
    {
        vector<int>rows;
        vector<int>columns;
        int sum,maxSum=INT_MIN;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=0;j<n;j++){
                sum+=m[i][j];
            }
            maxSum=max(maxSum,sum);
            rows.push_back(sum);
        }
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=0;j<n;j++){
                sum+=m[j][i];
            }
            maxSum=max(maxSum,sum);
            columns.push_back(sum);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=maxSum-rows[i];
        }
        return ans; 
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends