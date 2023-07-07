//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    
        void swapEle(long long arr1[], long long arr2[], int left, int right){//swap the elements if they are in wrong order
            if(arr1[left]>arr2[right]){
                swap(arr1[left],arr2[right]);
            }
        }
    
        void merge(long long arr1[], long long arr2[], int n, int m) //by striver
        { // using gap method
            int len=n+m;
            int gap=(len/2)+(len%2);//ceil value of len/2
            while(gap>0){
                int left=0,right=gap+left;
                while(right<len){
                    // left is in arr1 and right is in arr2
                    if(left<n &&  right>=n){
                        swapEle(arr1,arr2,left,right-n);
                    }
                    // left is in arr2 and right will always be in arr2
                    else if(left>=n){
                        swapEle(arr2,arr2,left-n,right-n);
                    }
                    // left is in arr1 and right is in arr1
                    else if(left<n &&  right<n){
                        swapEle(arr1,arr1,left,right);
                    }
                    left++;
                    right++;
                }
                if(gap==1){
                    break;//agr gap==1 phirse hota h toh (repetition)
                }
                gap=(gap/2)+(gap%2);//ceil value of gap/2
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends