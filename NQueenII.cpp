class Solution {
    vector<int> sol;
    int size;
    int c;
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        size = n;
        c = 0;
        sol.resize(n);
        if(n != 0) CountNQueen(0);
        return c;
    }
    
    bool isValid(int row) {
        for(int i = 0; i < row; ++i) {
            if(sol[i] == sol[row] || abs(sol[i] - sol[row]) == row - i) return false;
        }
        return true;
    }
    
    
    void CountNQueen(int level) {
        if(level == size) ++c;
        else {
            for(int i = 0; i < size; ++i) {
                sol[level] = i;
                if(isValid(level)) CountNQueen(level + 1);
            }
        }
    }
};
//Time Limit Exceeded
