class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<int, bool> visited;
        unordered_map<char, int> cnt;
        
        for (auto c : word) {
            cnt[c] += 1;
        }
        
        auto maxVal = max_element(cnt.begin(), cnt.end(), [](const auto &x, const auto &y) {
                    return x.second < y.second;});

        if (cnt[word[0]] == cnt[maxVal->first]) {
            reverse(word.begin(), word.end());
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (exist(board, word, i, j, 0, visited))
                    return true;
            }
        }
        
        return false;
    }
private:
    bool exist(vector<vector<char>>& board, string& word, int row, int col, int idx, unordered_map<int, bool> visited) {
        if (visited[row*10+col]) return false;
        if (row >= board.size() || col >= board[0].size() || row < 0 || col < 0) return false;
        else if (board[row][col] == word[idx]) {
            if (idx == word.size() - 1) 
                return true;
            else {
                visited[row*10 + col] = true;
                return exist(board, word, row - 1, col, idx+1, visited) 
                        || exist(board, word, row + 1, col, idx+1, visited)
                        || exist(board, word, row, col - 1, idx+1, visited) 
                        || exist(board, word, row, col + 1, idx+1, visited);
            }     
        }
        else return false;
    }
};