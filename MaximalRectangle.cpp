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
                    rightCol = leftCol; //�������ΪleftCol + 1,���ǵ�leftCol >= matrix[0].size()ʱ�򣬻���ִ����⡣
		    //��Ϊ�Һ�����maxline����䣬�����ж�leftCol�ĺϷ���
                    while(rightCol < matrix[0].size() && sum[j][rightCol] - sum[i - 1][rightCol] ==  j - i + 1) rightCol++;
                    maxline = max(rightCol - leftCol, maxline); //��Ҫ�ǳ�ע��leftcol��rightCol����Ч�����
                    leftCol = rightCol + 1; 
                }
                maxval = max(maxline * (j - i + 1), maxval);
            }
        }
        
        return maxval;        
    }
};

