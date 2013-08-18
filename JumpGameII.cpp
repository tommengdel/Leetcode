class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int step = 0;
        int oldfar = -1, far = 0, newfar = 0; //old farthest; current farthest; new farthest
        while(far != n - 1) {
            for(int i = oldfar + 1; i <= far; ++i) newfar = max(newfar, A[i] + i);
            if(newfar == far) return -1; //We can't get to the destination
            oldfar = far;
            far = newfar;
            ++step; 
        }
        return step;
    }
};

