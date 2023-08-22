class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board;
        string s = "";
        for (int i = 0; i < n; i++) {
            s.push_back(' ');
        }
        vector<string> ex(n,s);
        
        solveQueens(n, 0, board, ex);

        return board;
    }
    
    void solveQueens(int& n, int curr, vector<vector<string>>& board, vector<string> ex) {
        if (curr == n) { 
            board.push_back(ex);
            return;
        }
           
        auto idx = ex[curr].find(' ', 0);

        while (idx != string::npos) {
            vector<string> exSub(ex);
            exSub[curr][idx] = 'Q';
            operateQueen(n, curr, idx, exSub);
            solveQueens(n, curr+1, board, exSub);
            idx = ex[curr].find(' ', idx+1);
        }      
    }
    
    void operateQueen(int& n, int curr, int idx, vector<string>& ex) {
        for (int i = 0; i < n; i++) {
            if (i != idx)
                ex[curr][i] = '.';
            if (ex[i][idx] == ' ')
                ex[i][idx] = '.';
        
            if (i != curr) {
                int res = curr > i? curr - i : i- curr;
                if (idx - res >= 0 && ex[i][idx-res] == ' ') 
                    ex[i][idx-res] = '.';
                if (idx + res < n && ex[i][idx+res] == ' ')
                    ex[i][idx+res] = '.';
            }
        }
    }
};