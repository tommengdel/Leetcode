class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> pascal(rowIndex + 1);
        int lastLine_prev = 0;
        
        
        //Initialization
        pascal[0] = 1;
        
        for(int i = 1; i <= rowIndex; ++i) { //Will invoke size() every time?
            lastLine_prev = pascal[0];
            
            for(int j = 1; j < i; ++j) {
                int temp = pascal[j];
                pascal[j] = pascal[j] + lastLine_prev;
                lastLine_prev = temp;
            }
            
            pascal[i] = 1;
        }
        
        return pascal;
    }
};

//Accepted
