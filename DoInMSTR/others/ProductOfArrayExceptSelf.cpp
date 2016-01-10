class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() < 1) return vector<int>();
        vector<int> result(nums.size());
        result[0] = nums[0];
        for(int i = 1; i < nums.size() - 1; ++i) {
            result[i] = result[i - 1] * nums[i];
        }
        
        int init = 1;
        result[result.size() - 1] = result[result.size() - 2];
        for(int i = result.size() - 2; i > 0; --i) {
            init *= nums[i + 1];
            result[i] = result[i - 1] * init;
        }
        
        result[0] = init * nums[1];
        
        return result;
        
        
    }
};