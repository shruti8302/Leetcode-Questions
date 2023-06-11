//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void subSum(vector<int> arr, int n,vector<int> &ans, int ind, int sum){
        
        if(ind == n){
            ans.push_back(sum);
            return;
        }
        
        sum += arr[ind];
        subSum(arr, n, ans, ind+1, sum);
        sum -= arr[ind];
        subSum(arr, n, ans, ind+1, sum);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        subSum(arr, n, ans, 0, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends