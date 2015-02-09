class Solution {
    void swap(int &a, int &b) {
        int temp = a; 
        a = b; 
        b = temp;
    }
public:
    int majorityElement(vector<int> &num) {
        if(num.size() == 0) return -999;
        int i = 0, j = i;
        while(j < num.size()) {
            if(num[i] != num[j]) {
                swap(num[i + 1], num[j]);
                i += 2;
            }
            ++j;
        }
        if(i >= num.size()) return -999;
        return num[i];
    }
};
