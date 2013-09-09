class Solution {
    void InitDigitToChar(vector<string> & dtoc) {
        dtoc.assign(10, "");
        dtoc[0] = " ";
        dtoc[1] = "1";
        dtoc[2] = "abc";
        dtoc[3] = "def";
        dtoc[4] = "ghi";
        dtoc[5] = "jkl";
        dtoc[6] = "mno";
        dtoc[7] = "pqrs";
        dtoc[8] = "tuv";
        dtoc[9] = "wxyz";
    }
    
    vector<string> digitToChar;
    
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        InitDigitToChar(digitToChar);
        vector<string> combs;
        string oneComb;
        Generate(digits, 0, oneComb, combs);
        return combs;
    }
    
    void Generate(string& digits, int level, string& oneComb, vector<string>& combs) {
        if(level == digits.size()) combs.push_back(oneComb);
        else {
            if(!isdigit(digits[level])) {
                oneComb.push_back(digits[level]);
                Generate(digits, level + 1, oneComb, combs);
                oneComb.pop_back();
            }
            else {
                int i = digits[level] - '0';
                for(int t = 0; t < digitToChar[i].size(); ++t) {
                    oneComb.push_back(digitToChar[i][t]);
                    Generate(digits, level + 1, oneComb, combs);
                    oneComb.pop_back();

                }
            }
        }
    }
    
    
};

