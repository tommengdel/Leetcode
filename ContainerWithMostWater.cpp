class Solution {
    inline int MAX(int a, int b) { return a > b ? a : b; }
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> index(height.size());
        for(int i = 0; i < height.size(); i++) index[i] = i;
         
        struct cmp {
            vector<int> & v;
            cmp(vector<int> &v): v(v) {}
            bool operator() (const int & ind1, const int &ind2) {
                return v[ind1] < v[ind2];
            }
        };
        sort(index.begin(), index.end(), cmp(height));
        vector<int> maxInd(height.size()), minInd(height.size());
        int max = 0, min = height.size() - 1;
        for(int i = height.size() - 1; i >= 0; --i) {
            if(index[i] > max) max = index[i];
            if(index[i] < min) min = index[i];
            
            maxInd[i] = max;
            minInd[i] = min;
        }
        int maxCon = 0;
        for(int i = 0; i < height.size() - 1; ++i) {
           int curMax = MAX(abs(index[i] - minInd[i + 1]), abs(maxInd[i + 1] - index[i])) * height[index[i]];
           maxCon = maxCon ? curMax : maxCon : curMax; 
        }
        return maxCon;
    }
 };

//Accepted
