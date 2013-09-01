class Solution {
    int binary_search(vector<int> &num, int low, int high, int target) {
        int mid;
        while(low < high) {
            mid = low + (high - low) / 2;
            if(num[mid] >= target) high = mid;
            else low = mid + 1;
        }
        return high;
    }
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(num.size() < 3) return target;   
        int closest;
        closest = num[0] + num[1] + num[2];
        
        sort(num.begin(), num.end());
        
        for(int i = 0; i < num.size() - 2; ++i) {
            for(int j = i + 1; j < num.size() - 1; ++j) {
                int k = binary_search(num, j + 1, num.size() - 1, target - num[i] - num[j]);
                if(abs(num[i] + num[j] + num[k] - target) < abs(closest - target)) 
                    closest = num[i] + num[j] + num[k];
                if(k > j + 1) {
                    if(abs(num[i] + num[j] + num[k - 1] - target) < abs(closest - target)) 
                    closest = num[i] + num[j] + num[k - 1];
                }
            }
        }
        
        return closest;
    }
};

