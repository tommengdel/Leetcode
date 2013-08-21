class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int forward = 0, backward = s.size() - 1;
        bool ret = true;
        
        
        while(forward < s.size() && !isalnum(s[forward])) ++forward;
        while(backward > - 1 && !isalnum(s[backward])) --backward;
        
        while(forward < backward) {
            if(toupper(s[forward]) != toupper(s[backward])) {
                ret = false;
                break;
            }
            ++forward; --backward; //忘记加这一行，导致死循环
            while(forward < s.size() && !isalnum(s[forward])) ++forward;
            while(backward > - 1 && !isalnum(s[backward])) --backward;
            
        }
        return ret;
    }
};
//我把10，11行的东西照搬到19,20. 错误了。
//适用的情况不同。
//不加上18行就会导致死循环。
//因为10,11行，可能不会更新forward 和backward
//似乎是缺少特别清晰的程序流程图。
