#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
class Solution {
    
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(height.size() < 2) return 0;
        int max = 0;
        
        class Elem {
	public:
            int height, index;
            Elem(int h = 0, int ind = 0) : height(h), index(ind) {}
            bool operator<(const Elem& e1)const {
                return height < e1.height;
            }
        };
        
        class gen {
            vector<int> &v;
            
            int cur;
        public:
            gen(vector<int> &v) :v(v), cur(0) {}
            Elem operator()(){
                Elem ret(v[cur], cur);
                ++cur;
                return ret;
            }
        };
        
        vector<Elem> heightIndex;
        generate_n(back_inserter(heightIndex), height.size(), gen(height));
        sort(heightIndex.begin(), heightIndex.end());      
        
        vector<bool> containerVisited;
        containerVisited.assign(height.size(), false);
        int left = 0, right = height.size() -1;
        
        //可以使用for_each
        for(int i = 0; i < heightIndex.size(); ++i) {
            Elem &e = heightIndex[i];
            containerVisited[e.index] = true;        
            
            //Start to get the max container
            int con1 = e.height * (e.index - left);
            int con2 = e.height * (right - e.index);
            
            max = max > con1 ? max : con1;
            max = max > con2 ? max : con2;
            //Advance left and right
            while(containerVisited[left] == true) ++left;
            while(containerVisited[right] == true) --right;
        }
        return max;
    }
    
};
int main() {
	int a[] = {1, 1};
	vector<int> height(a, a + 2);
	Solution().maxArea(height);
}

//Not accepted , I am not familiar with the algorithm in STL!! 
