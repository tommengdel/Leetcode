class Solution {
    vector<string> sols;
    vector<int> oneSol;
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        oneSol.clear(), sols.clear();
        oneSol.push_back(0);
        Generate(s, 0, 1);
        return sols;
    }
    
    void Generate(string &s, int startPos, int ithnum) {
        if(startPos == s.size()) {
            if(ithnum == 5) {
                string sol = "";
                for(int i = 0; i < oneSol.size() - 1; ++i) {
                    sol += s.substr(oneSol[i], oneSol[i + 1] - oneSol[i]);
                    sol += ".";
                }
                sol.pop_back();
                sols.push_back(sol);
            }
            else return;
        }
        
        if(ithnum == 5) return;
        int num = 0;
        for(int j = startPos; j < s.size(); ++j) {
            num = num * 10 + s[j] - '0';
            if(num <= 255) {
                oneSol.push_back(j + 1);
                Generate(s, j + 1, ithnum + 1);
                oneSol.pop_back();
            }
            else break;
            if(num == 0) break; //防止0.010.0000.10的情况出现
        }
    }
    
};

