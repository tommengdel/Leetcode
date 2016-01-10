
class Solution {
    class Node {
        public:
            int value;
            int index;

            Node(int i, int v) : value(v), index(i) {
            }

            Node(){}

            bool operator <=(const Node& n1) {
                return value <= n1.value;
            }
    };

    void mergeSort(vector<Node> &array, int left, int right, vector<int> &count) {
        if(left == right) return;

        //Sort the array[left...right]
        int arrayLen = right - left + 1;
        int leftLen = arrayLen / 2;
        int rightLen = arrayLen - leftLen;

        mergeSort(array, left, left + leftLen - 1, count);
        mergeSort(array, left + leftLen, right, count);

        //Start the merge process
        vector<Node> auxArray;
		auxArray.clear();
        int leftIndex = left;
        int rightIndex = left + leftLen;
        while(leftIndex < left + leftLen && rightIndex < right + 1) {
            //compare array[leftIndex] and array[rightIndex]
            if(array[leftIndex] <= array[rightIndex]) {
                auxArray.push_back(array[leftIndex]);
                //Update the i
                count[array[leftIndex].index] += rightIndex - (left + leftLen);
                ++leftIndex;
            } else {
                auxArray.push_back(array[rightIndex]);
                ++rightIndex;
            }
        }

        //process the remaining element
        while(leftIndex < left + leftLen) {
            auxArray.push_back(array[leftIndex]);
            count[array[leftIndex].index] += rightLen;
            ++leftIndex;
        }

        while(rightIndex < right + 1) {
             auxArray.push_back(array[rightIndex]);
             ++rightIndex;
        }

        //copy the element to original array
        for(int i = 0 ; i < auxArray.size(); ++i) {
            array[left + i] = auxArray[i];
        }

    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0) return nums;
        vector<Node> numIndexs(nums.size());
		numIndexs.clear();
        for(int i = 0; i < nums.size(); ++i) {
            numIndexs.emplace_back(i, nums[i]);
        }

        vector<int> count(nums.size(), 0);

        mergeSort(numIndexs, 0, nums.size() - 1, count);
        return count;
    }
};
