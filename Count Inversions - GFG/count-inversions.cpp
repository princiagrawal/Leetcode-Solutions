//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    
    long long int merge(long long arr[], long long l,long long mid,long long h){
        vector<long long>temp;
        long long int count=0;
        long long left=l,right=mid+1;
        while(left<=mid && right<=h){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            //right element is smaller
            else{
                temp.push_back(arr[right]);
                count+=(mid-left+1);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=h){
            temp.push_back(arr[right]);
            right++;
        }
        for(long long i=l;i<=h;i++){
            arr[i]=temp[i-l];
        }
        return count;
    }
    
    long long int mergeSort(long long arr[], long long l,long long h){
        long long int ans=0;
        if(l>=h){
            return ans;
        }
        long long mid=l+(h-l)/2;
        ans+=mergeSort(arr,l,mid);
        ans+=mergeSort(arr,mid+1,h);
        ans+=merge(arr,l,mid,h);
        return ans;
        
    }
    
    long long int inversionCount(long long arr[], long long N)//by striver
    {
        return mergeSort(arr,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends