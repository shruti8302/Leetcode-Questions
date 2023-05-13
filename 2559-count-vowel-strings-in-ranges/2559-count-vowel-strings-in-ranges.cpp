class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> dummy(words.size(), 0);
        
        string s = "aeiou";
        
        int k = 0;
        for(auto st: words){
           if(s.find(st[0]) != string::npos && s.find(st.back()) != string::npos){
                    dummy[k++] = 1;
                }else{
                    dummy[k++] = 0;
                }
             
        }
            
        
        for(int i = 1;i < dummy.size();i++){
            dummy[i] += dummy[i-1];
        }
        for(auto q: queries){
            int s = q[0];
            int e = q[1];
            if(s == 0){
                ans.push_back(dummy[e]);
            }else{
                ans.push_back(dummy[e]-dummy[s-1]);
            }
            
        }
        return ans;
    }
};