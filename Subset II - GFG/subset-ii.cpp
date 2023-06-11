//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
  
    void print(vector<int> nums,vector<vector<int>>& ans,vector<int> v, int ind){
        
            ans.push_back(v);
            
        for(int i = ind;i < nums.size();i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
            v.push_back(nums[i]);
            print(nums, ans, v, i+1);
            v.pop_back();
        }
        
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        print(nums, ans, v, 0);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends