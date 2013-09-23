class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxval = 0;
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<int> tmp(matrix[0].size());
        vector<vector<int> > sum(matrix.size(), tmp);
        for(int col = 0; col < matrix[0].size(); ++col) {
            sum[0][col] = matrix[0][col] - '0';
            for(int row = 1; row < matrix.size(); ++row) 
                sum[row][col] = sum[row - 1][col] + matrix[row][col] - '0';
        }
        
        //Start to compute
        //[row_i ... row_j][col] as a number
        for(int j = 0; j < matrix.size(); ++j) {
                int leftCol = 0, rightCol = 0;
                int maxline = 0;
                //Init leftCol
                while(leftCol < matrix[0].size()) {
                    while(leftCol < matrix[0].size() && sum[j][leftCol] !=  j + 1) leftCol++; 
                    rightCol = leftCol;
                    while(rightCol < matrix[0].size() && sum[j][rightCol] ==  j + 1) rightCol++;
                    maxline = max(rightCol - leftCol, maxline);
                    leftCol = rightCol + 1; 
                }
                maxval = max(maxline * (j + 1), maxval);
            }
        
        
        for(int i = 1; i < matrix.size(); ++i) {
            for(int j = i; j < matrix.size(); ++j) {
                int leftCol = 0, rightCol = 0;
                int maxline = 0;
                //Init leftCol
                while(leftCol < matrix[0].size()) {
                    while(leftCol < matrix[0].size() && sum[j][leftCol] - sum[i - 1][leftCol] !=  j - i + 1) leftCol++; 
                    rightCol = leftCol; //起初设置为leftCol + 1,但是当leftCol >= matrix[0].size()时候，会出现大问题。
		    //因为我后面求maxline的语句，并不判断leftCol的合法性
                    while(rightCol < matrix[0].size() && sum[j][rightCol] - sum[i - 1][rightCol] ==  j - i + 1) rightCol++;
                    maxline = max(rightCol - leftCol, maxline); //需要非常注意leftcol和rightCol都无效的情况
                    leftCol = rightCol + 1; 
                }
                maxval = max(maxline * (j - i + 1), maxval);
            }
        }
        
        return maxval;        
    }
};

