//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        long long ans = -1;
        long long si = 0;
        long long ei = n-1;
        // long long maxEl = -1;
        
        while(si <= ei){
            long long mid = si + (ei-si)/2;
            if(v[mid] == x){
                return mid;
            }else if(v[mid] < x){
                ans = mid;
                //maxEl = max(maxEl,ans);
                si = mid+1;
            }else{
                ei = mid-1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends