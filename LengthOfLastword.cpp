//Correct Solution
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = strlen(s);
        int l, r;
        l = 0;
        int lastlen = 0;
        while(l < len && *(s + l) == ' ') ++l;
        r = l + 1;
        while(r <= len) {
            while(r < len && *(s + r) != ' ') ++r; // r <= len is incorrect
            lastlen = r - l;
            
            l = r + 1;
            while(l < len && *(s + l) == ' ') ++l;
            r = l + 1;
        }
        return lastlen;
    }
};
//Accepted


//InCorrect Solution
//

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = strlen(s);
        int l, r;
        l = 0;
        int lastlen = 0;
        while(l < len && *(s + l) == ' ') ++l;
        r = l + 1;
        while(r <= len) {
            while(r <= len && *(s + r) != ' ') ++r;
            lastlen = r - l;
            
            l = r + 1;
            while(l < len && *(s + l) == ' ') ++l;
            r = l + 1;
        }
        return lastlen;
    }
};
//My Test Case:
// "a   " "     day"  "  day " "abcd efg" 
//Error Test Case: "a"
//



