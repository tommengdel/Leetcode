class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool lastColZero = false, lastRowZero = false;
        int m = matrix.size();
        if(m < 1) return;
        int n = matrix[0].size();
        
        //A m * n matrix
        for(int i = 0; i < n; ++i) {
            if(matrix[m - 1][i] == 0) lastRowZero = true;
        }
        for(int i = 0; i < m; ++i)
            if(matrix[i][n - 1] == 0) lastColZero = true;
        
        for(int i = 0; i < m - 1; ++i) 
            for(int j = 0; j < n - 1; ++j) {
                if(matrix[i][j] == 0) 
                    matrix[i][n - 1] = matrix[m - 1][j] = 0;
            }
            
        for(int i = 0; i < m - 1; ++i) 
            for(int  j = 0; j < n - 1; ++j) 
                if(matrix[i][n - 1] == 0 || matrix[m - 1][j] == 0) 
                    matrix[i][j] = 0;
        if(lastColZero) 
            for(int i = 0; i < m; ++i) matrix[i][n - 1] = 0;
        if(lastRowZero)
            for(int i = 0; i < n; ++i) matrix[m - 1][i] = 0;
    }
};

//犯了5个编译Error 我个sb，越是简单的题目越是傻x
//12ms 388ms
