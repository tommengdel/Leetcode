class Solution {
    int binary_search(vector<int> &num, int low, int high, int target) {
        int mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(num[mid] == target) return mid;
            else if(num[mid] < target) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return -1;
    }
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(num.size() < 3) return ret;
        struct index
        { 
            int ind1, ind2 ;
            index(int ind1,int ind2) :ind1(ind1),ind2(ind2) {}
            bool operator<(const struct index& i2)const {
                return ind1 < i2.ind1 || (ind1 == i2.ind1 && ind2 < i2.ind2);
            }
        };
        set<index> isDup;
        isDup.clear();
        sort(num.begin(), num.end());
        //int prevTwoSum;
        //bool Init = false;
        for(int i = 0; i < num.size() - 2; ++i) 
            for(int j = i + 1; j < num.size() - 1; ++j) {  
                if(isDup.find(index(num[i], num[j])) != isDup.end()) continue;
                int k =  binary_search(num, j + 1, num.size() -1 , 0 - num[i] - num[j]);
                if(k != -1) {
                    ret.push_back(vector<int>());
                    ret.back().push_back(num[i]);
                    ret.back().push_back(num[j]);
                    ret.back().push_back(num[k]);
                    isDup.insert(index(num[i], num[j]));
                }
          //      prevTwoSum = num[i] + num[j];
            }
        return ret;
    }
};
//A error about stl::set usage
//You must accurately define the operator < 
//Because set define (a == b) as (!(a < b) && !(b < a)) 
//I make a big mistake
