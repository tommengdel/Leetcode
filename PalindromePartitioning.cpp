class Solution {
    vector<string> oneSol;
    vector<vector<string> > Sols;
    vector<vector<bool> > ispalin;
public:
    void generatePalindrome(string &s, int index) {
        if(index == s.size()) Sols.push_back(oneSol);
        for(int i = index; i < s.size(); ++i) {
            if(!ispalin[index][i]) continue;
            oneSol.push_back(s.substr(index, i - index + 1));
            generatePalindrome(s, i + 1);
            oneSol.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         //ispalin[i][j] : s[i.. j] is palindrome
        vector<bool> tmp(s.size(), true);
        ispalin.assign(s.size(), tmp);
        oneSol.clear(); Sols.clear();
        for(int i = 0; i < s.size(); ++i) ispalin[i][i] = true;
        
        for(int dist = 1; dist <= s.size() - 1; ++dist) { //[i, i + dist]
            for(int i = 0; i < s.size() - dist; ++i) 
                ispalin[i][i + dist] = (s[i] == s[i + dist] && ispalin[i + 1][i + dist - 1]);
        }
        
        //Start to backtrack
        generatePalindrome(s, 0);
        return Sols;
    }
};

