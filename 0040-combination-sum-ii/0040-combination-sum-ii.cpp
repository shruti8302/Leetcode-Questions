class Solution {
public:
    
    void combSum(vector<int>& arr,int remSum, int ind, vector<int> res,  vector<vector<int>> &ans){
        
            if(remSum == 0){
                ans.push_back(res);
                return;
            }
        
        for(int i = ind;i < arr.size();i++){
            if(i > ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > remSum) break;
            res.push_back(arr[i]);
            combSum(arr, remSum - arr[i], i+1, res, ans);
            res.pop_back();
        }
        
    }
        
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> res;
        combSum(arr, target, 0, res, ans);
        return ans;
    }
};