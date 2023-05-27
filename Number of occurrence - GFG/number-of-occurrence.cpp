//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int firstIdx(int arr[], int n, int x){
	    
	    int si = 0;
	    int ei = n-1;
	    int ans = -1;
	    
	    while(si <= ei){
	        int mid = si + (ei-si)/2;
	        if(arr[mid] == x){
	            ans = mid;
	            ei = mid-1;
	        }else if(arr[mid] > x){
	            ei = mid-1;
	        }else{
	            si = mid+1;
	        }
	    }
	    return ans;
	}
	
	int lastIdx(int arr[], int n, int x){
	    
	    int si = 0;
	    int ei = n-1;
	    int ans = -1;
	    
	    while(si <= ei){
	        int mid = si + (ei-si)/2;
	        if(arr[mid] == x){
	            ans = mid;
	            si = mid+1;
	        }else if(arr[mid] > x){
	            ei = mid-1;
	        }else{
	            si = mid+1;
	        }
	    }
	    return ans;
	}
	
	int count(int arr[], int n, int x) {
	  
	    int firstOcc = firstIdx(arr, n, x);
	    int lastOcc = lastIdx(arr, n, x);
	    
	    if(firstOcc == -1) return 0;
	    
	    return (lastOcc - firstOcc + 1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends