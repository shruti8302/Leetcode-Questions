class Solution {
public:
    
    void combSum(int i, vector<int>& candidates, vector<vector<int>> &ans, int remSum,vector<int> res){
        
        if(i == candidates.size()){
            if(remSum == 0){
                ans.push_back(res);
            }
             return;
        }
        if(remSum >= candidates[i]){
            res.push_back(candidates[i]);
            combSum(i, candidates, ans, remSum - candidates[i], res);
            res.pop_back();
        }
        combSum(i+1, candidates, ans, remSum, res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> res;
        
        combSum(0, candidates, ans, target, res);
        
        return ans;
    }
};