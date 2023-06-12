class Solution {
public:
    
    bool canPlaceQueen(int row, int col, vector<string>&boards, int n){
        
        int r = row;
        int c = col;
        
        while(r >= 0 && c >= 0){
            if(boards[r][c] == 'Q') return false;
            r--;
            c--;
        }
        
        r = row; 
        c = col;
        
        while(c >= 0){
            if(boards[r][c] == 'Q') return false;
            c--;
        }
        
        r = row; 
        c = col;
        
        while(r < n && c >= 0){
            if(boards[r][c] == 'Q') return false;
            r++;
            c--;
        }
        return true;
    }
    
    void solve(int col, int n, vector<vector<string>> &ans, vector<string> boards){
        if(col == n){
            ans.push_back(boards);
            return;
        }
        for(int row = 0;row  < n;row++){
            if(canPlaceQueen(row, col, boards, n)){
                boards[row][col] = 'Q';
                solve(col+1, n, ans, boards);
                boards[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> boards(n);
        string s(n, '.');
        for(int i = 0;i < n;i++){
            boards[i] = s;
        }
        solve(0, n, ans, boards);
        
        return ans;
    }
};