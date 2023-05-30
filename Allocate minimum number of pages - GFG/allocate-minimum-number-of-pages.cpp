//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isValid(int arr[], int n, int m, int maxPages){
        
        int student = 1;
        int sum = 0;
        
        for(int i = 0;i < n;i++){
            sum += arr[i];
            if(sum > maxPages){
                student++;
                sum = arr[i];
            }
            if(student > m) return false;
        }
        
        return true;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        int si = *max_element(arr, arr+n);
        int ei = accumulate(arr, arr+n, 0);
        
        if(m > n){
            return -1;
        }
        
        int res = -1;
        
        while(si <= ei){
            
            int mid = si + (ei-si)/2;
            
            if(isValid(arr, n, m, mid)){
                res = mid;
                ei = mid-1;
            }else{
                si = mid+1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends