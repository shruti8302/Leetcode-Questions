class Solution {
public:
    string minWindow(string s, string t) {
        int count = 0;
        int i = 0, j = 0;
        
        unordered_map<char, int> mp;
        
        for(int k = 0;k < t.size();k++){
            mp[t[k]]++;
        }
        
        count = mp.size();
        int n = s.size();
        int minLen = INT_MAX;
        
        int si = 0, ei = 0;
        
        while(j < n){
            if(count > 0){
                if(mp.find(s[j]) != mp.end()){
                    mp[s[j]]--;
                    if(mp[s[j]] == 0){
                        count--;
                    }
                }
               
            }
                while(count == 0){
                    int currLen = j-i+1;
                    if(currLen < minLen){
                        minLen = currLen;
                        si = i;
                        ei = j-i+1;
                    }
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1){
                            count++;
                        }
                    }
                    i++;
                }
            
             j++;
        }
        string str = "";
         if(minLen != INT_MAX){
             return str.append(s.substr(si,ei));
         }else{
             return str;
         }
            
        
    }
};