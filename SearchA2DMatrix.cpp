class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m,n;
        if((m = matrix.size()) == 0 || (n = matrix[0].size()) == 0) return false;
        //Find A[high][0] > target
        int low = 0, high = m - 1, mid;
        while(low < high) {
            mid = low + (high - low) / 2;
            if(matrix[mid][0] > target) high = mid;
            else if(matrix[mid][0] == target) return true;
            else low = mid + 1;
        }
        
        if(matrix[high][0] > target) 
            return high == 0 ? false : binary_search(matrix[high - 1].begin(), matrix[high - 1].end(), target);
        else return binary_search(matrix[high].begin(), matrix[high].end(), target);
    }
};
//Use STL Algorithm
