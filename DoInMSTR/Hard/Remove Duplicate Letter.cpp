class Solution {
    int getIndex(char c) {
        return c - 'a';
    }
public:
    string removeDuplicateLetters(string s) {
        const int N = 26;
        int count[N];
        bool added[N];
        for(int i = 0; i < N; ++i) {
            count[i] = 0;
            added[i] = false;
        }
        
        //Optimization: remove consecutive same character
        int newSize = 1;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == s[i - 1]) continue;
            else s[newSize++] = s[i];
        }
        
        s.resize(newSize);
        
       for(int i = 0; i < s.size(); ++i) {
           ++count[getIndex(s[i])];
       }
       
       stack<char> charStack;
       for(int i = 0; i < s.size(); ++i) {
           --count[getIndex(s[i])];
           if(added[getIndex(s[i])]) continue;
           
           while(!charStack.empty() && charStack.top() > s[i] && count[getIndex(charStack.top())] > 0) {
               added[getIndex(charStack.top())] = false;
               charStack.pop();
           }
           
           charStack.push(s[i]);
           added[getIndex(s[i])] = true;
       }
       
       string result("");
       while(!charStack.empty()) {
           result.push_back(charStack.top());
           charStack.pop();
       }
       reverse(result.begin(), result.end());
       return result;
        
    }
};