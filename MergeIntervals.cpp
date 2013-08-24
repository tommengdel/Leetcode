/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool InRange(int v, int below, int above) const {
        return v >= below && v <= above;
    }
    bool overlap(const Interval &a,const Interval& b) const {
        return InRange(a.start, b.start, b.end) || InRange(a.end, b.start, b.end);
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        struct cmp {
            bool operator()(const Interval&a, const Interval& b) {
                return a.start < b.start;
            }
        };
        vector<Interval> newIntervals;
        sort(intervals.begin(), intervals.end(),cmp());
        int rightEnd, leftEnd;
        int i = 0, j;
        while(i < intervals.size()) {
            leftEnd = intervals[i].start;
            rightEnd = intervals[i].end;
            
            j = i + 1;
            while(overlap(intervals[j], intervals[j - 1])) { 
                if(intervals[j].end > rightEnd) rightEnd = intervals[j].end;
                ++j;
            }
            newIntervals.push_back(Interval(leftEnd, rightEnd));
            i = j;
        }
        
        return newIntervals;
        
    }
};
//Error Test Case: [2, 3] [4, 5] [6, 7] [8, 9] [1, 10].. 
//I can Understand why~~ 
//Error Test Case2 :input	output	expected	
//[[2,2],[1,3],[3,3],[3,4],[2,3],[4,5],[4,4]]	[[1,6]]	[[1,5]]

