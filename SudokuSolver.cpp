class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int SUDOKUSIZE = 9;
        vector<bool> tmp(SUDOKUSIZE, false);
        vector<vector<bool> > isOccupiedSubBox(SUDOKUSIZE, tmp), isOccupiedCol(isOccupiedSubBox), isOccupiedRow(isOccupiedSubBox);
        for(int i = 0; i < board.size(); ++i) 
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] != '.') {
                    int t = GetSubBox(i, j);
                    isOccupiedSubBox[t][board[i][j] - '1'] = true;
                    isOccupiedRow[i][board[i][j] - '1'] = true;
                    isOccupiedCol[board[i][j] - '1'][j] = true;
                }
            }
    }
};
//启发式回溯
//先去解某列上填好的个数较多的地方
//Not finished
