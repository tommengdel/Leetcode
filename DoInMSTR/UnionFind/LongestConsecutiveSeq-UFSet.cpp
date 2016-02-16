class UFSet {
	private:
		int N;
		vector<int> uf;
		vector<int> sz;
	public:
		UFSet(int n) : N(n) {
			uf.resize(n, 0);
			sz.resize(n, 1);
			for(int i = 0; i < N; ++i) uf[i] = i;
		}

		void quick_union(int x, int y) {
		  //  cout<<"Union"<<x<<" "<<y<<endl;
			int xRoot = find(x);
			int yRoot = find(y);

			if(sz[xRoot] > sz[yRoot]) {
				uf[yRoot] = xRoot;
				sz[xRoot] += sz[yRoot];
			} else {
				uf[xRoot] = yRoot;
				sz[yRoot] += sz[xRoot];
			}
		}

		int find(int x) {
			while(x != uf[x]) {
				uf[x] = uf[uf[x]];
				x = uf[x];
			}

			return x;
		} 

		bool isSameSet(int x, int y) {
			return find(x) == find(y);
		}
		
		
		int findMaxSetSize() {
		    int maxSize = 0;
		    
		    for(int i = 0; i < N; ++i) {
		        if(i == uf[i]) maxSize = max(maxSize, sz[i]);
		    }
		    
		    return maxSize;
		}

};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int, int> map;
        
        UFSet uf(nums.size());
        
        for(int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = i;
        }
        unordered_map<int,int> ::iterator numIter;
        for(numIter = map.begin(); numIter != map.end(); ++numIter) {
            int num = numIter->first;
            int x = numIter->second;
            unordered_map<int, int> :: iterator it = map.find(num - 1);
            if(it != map.end())
            uf.quick_union(x, it->second);
        }
        
        return uf.findMaxSetSize();
    }
};

