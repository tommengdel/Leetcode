class Solution {
public:
    bool dfs(vector<vector<char> >&board, int r, int c, string& word, int pos_w, vector<vector<bool> >& used) {
        bool ret = false;
        used[r][c] = true;
        
        if(pos_w == word.size() - 1) ret = true;
        
        if(!ret && r > 0 && board[r - 1][c] == word[pos_w + 1] && !used[r - 1][c]
            && dfs(board, r - 1, c, word, pos_w + 1, used)) ret = true; 
        if(!ret && r < board.size() - 1 &&  board[r + 1][c] == word[pos_w + 1] 
                &&!used[r + 1][c] && dfs(board, r + 1, c, word, pos_w + 1, used)) ret = true;
        if(!ret && c > 0 && board[r][c - 1] == word[pos_w + 1] &&!used[r][c - 1]
            && dfs(board, r, c - 1, word, pos_w + 1, used)) ret = true;
        if(!ret && c < board[0].size() - 1 && board[r][c + 1] == word[pos_w + 1] 
                &&!used[r][c + 1] && dfs(board, r, c + 1, word, pos_w + 1, used)) ret = true; 
        
        
        used[r][c] = false;
        return ret;
        
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.size() == 0) return false;
        if(word.size() == 0) return true;
        vector<bool> tmp(board[0].size(), false);
        vector<vector<bool> >used(board.size(), tmp);
        
        bool ret = false;
        for(int i = 0; i < board.size(); ++i) 
            for(int j = 0; j < board[0].size(); ++j) {
                //board[i][j] will be the first station of word
                if(board[i][j] == word[0]) {
                    ret = dfs(board, i, j, word, 0, used);
                    if(ret) return ret;
                }
            }
        return ret;
    }
};

