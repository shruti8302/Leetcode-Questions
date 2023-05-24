class Solution {
public:
    #define ll long long
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> ans(n);
        
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0;i < n;i++){
            mp[nums[i]].push_back(i);
        }
        
        
        
        for(auto it: mp){
            int num = it.first;
            
            vector<int> &indexes = it.second;
            
            ll totalSum = 0;
            for(ll i = 0;i < indexes.size();i++){
                totalSum += indexes[i];
            }
             ll preSum = 0;
             ll postSum = 0;
            for(ll i=0;i < indexes.size();i++){
                int index = indexes[i];
                postSum = totalSum - preSum - index;
                
                ans[index]+=(index*(i));
                ans[index]-=preSum;
                ans[index]-=(index*(indexes.size()-i-1));
                ans[index]+=postSum;
                
                preSum += index;
            }
        }
        return ans;
    }
};