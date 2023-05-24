class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0; 
        
        int kIdx = find(begin(nums), end(nums), k)-begin(nums);
        int val = 0;
        
        for(int i = kIdx;i < nums.size();i++){
            if(nums[i] == k){
                val = 0;
            }else if(nums[i] > k) val++;
            else val--;
            mp[val]++;
        }
        val = 0;
        
        for(int i = kIdx;i >= 0;i--){
             if(nums[i] == k){
                val = 0;
            }else if(nums[i] > k) val++;
            else val--;
            ans += mp[-val]+mp[-val+1]; 
        }
        return ans;
    }
};