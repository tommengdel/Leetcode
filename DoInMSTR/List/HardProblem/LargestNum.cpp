string toString(int i) {
    return std::to_string(i);
}

bool compare(string num1, string num2) {
    return num1 + num2 > num2 + num1;
}
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> numString(num.size());
        transform(num.begin(), num.end(), numString.begin(), toString);
        sort(numString.begin(), numString.end(), compare);
        string result = "";
        result = accumulate(numString.begin(), numString.end(), result);
        //Remove the first 0, but not remove all zero.
        int notZero = 0;
        for(notZero = 0; notZero < result.size() - 1 && result[notZero] == '0'; notZero++);
        return result.substr(notZero, result.size() - notZero);
    }
};