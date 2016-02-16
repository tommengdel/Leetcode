class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int maxSize = 1;
        
        while(!s.empty()) {
            int curSize = 1;
            int ele = *s.begin(); s.erase(ele);
            int belowEle = ele;
            while(true) {
                unordered_set<int>::iterator it = s.find(--belowEle);
                if(it == s.end()) break;
                else {
                    ++curSize;
                    s.erase(it);
                }
            }
            
            int aboveEle = ele;
            while(true) {
                unordered_set<int>::iterator it = s.find(++aboveEle);
                if(it == s.end()) break;
                else {
                    ++curSize;
                    s.erase(it);
                }
            }
            
            maxSize = max(maxSize, curSize);
            
        }
        return maxSize;
    }
};