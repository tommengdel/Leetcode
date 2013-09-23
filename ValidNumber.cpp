class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s == 0) return false;
        int i = 0;
        const int ERROR = -1;
        const char *p = s;
        while(*p != 0) {
            switch(i) {
                case 0:
                    if(isdigit(*p)) i = 1;
                    else if(isspace(*p)) i = 0;
                    else if(*p == '-') i = 7;
                    else i = ERROR;
                    break;
                case 1:
                    if(isdigit(*p)) i = 1;
                    else if(*p == '.') i = 2;
                    else i = ERROR;
                    break;
                case 2:
                    if(isdigit(*p)) i = 3;
                    else i = ERROR;
                    break;
                case 3:
                    if(isdigit(*p)) i = 3;
                    else if(*p == 'E' || *p == 'e') {
                        i = 4;
                    } else i = ERROR;
                    break;
                case 4:
                    if(*p == '-') i = 5;
                    else if(isdigit(*p)) i = 6;
                    else i = ERROR;
                    break;
                case 5:
                    if(isdigit(*p)) i = 6;
                    else i = ERROR;
                case 6:
                    if(isdigit(*p)) i = 6;
                    else i = ERROR;
                case 7:
                    if(isdigit(*p)) i = 1;
                    else i = ERROR;
                    break;
                default:
                    i = ERROR;
            }//忘记考虑负数了
            ++p;
        }
        
        if(i != 1 && i != 3 && i != 6) return false;
        return true;
    }
};

