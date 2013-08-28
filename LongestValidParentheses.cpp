class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> Match(s.size(), false);
        typedef int index;
        stack<index> st;
        
        for(int i = 0; i < s.size(); ++i) {
            switch(s[i]) {
                case '(':
                    st.push(i); 
                    break;
                case ')':
                    if(!st.empty() && s[st.top()] == '(') {
                        Match[st.top()] = true;
                        Match[i] = true;
                        st.pop();
                    }
                    break;
                  default:
                        ;
            }
        }
        
        //Find the max length of true seq
        int i = 0; int maxLength = 0;
	while(i < Match.size()) {
            if(!Match[i]) {  //This is important
                ++i; continue;
            }
            int j = i;
            while(j < Match.size() && Match[j]) ++j; 
            if(j - i > maxLength) maxLength = j - i;
            i = j + 1;
        }
       
	/*
	 * This code can be changed
	 * while(i < Match.size() {
	 * 	int j = i - 1;
	 * 	while(Match[j + 1]) ++j;
	 *	if(j - i > maxLength) maxLength = j - i;
	 *	i = i > j ? i + 1 : j + 1; //Important i = j + 1 incur infinite loop
	 * }
	 
	 * */
        return maxLength;   
    }
};
//My Mistake: Cross-boundary Access; Count number error
//I Find a new Method , but it is Not Correct
/*
class Solution {
    int MIN(int a, int b) {
        return a < b ? a : b;
    }
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int leftPar = 0, rightPar = 0;
        int max = 0;
        for(int i = 0; i < s.size(); ++i) {
            switch(s[i]) {
            case '(':
                leftPar++;
                break;
            case ')':
                if(leftPar <= rightPar) {
                     max = max > leftPar ? max : leftPar;
                     leftPar = rightPar = 0;

                }
                else ++rightPar;
                break;
            }
        }
        
        int curMax = MIN(leftPar, rightPar);
        max = max > curMax ? max : curMax;
        return max * 2; //Forget to multiply by 2
     }
};
*/
//Test Case: ()(()  Output: 4 Expected: 2
//

