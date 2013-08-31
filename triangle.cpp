class Solution {
    int min(const int&a, const int&b) const {
        return a < b ? a : b;
    }
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(triangle.size() == 0) return 0;
        int lastLine_prev = 0;
        vector<int> total(triangle.size());
        
        //Initialization
        total[0] = triangle[0][0];
        
        for(int i = 1; i < triangle.size(); ++i) { //Will invoke size() every time?
            lastLine_prev = total[0];
            total[0] += triangle[i][0];
            for(int j = 1; j < i; ++j) {
                int temp = total[j];
                total[j] = min(total[j], lastLine_prev) + triangle[i][j];
                lastLine_prev = temp;
            }
            
            total[i] = lastLine_prev + triangle[i][i];
        }
        
        return *min_element(total.begin(), total.end());
    }
};
//Use only O(n) space

