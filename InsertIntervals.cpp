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
    //Find the first i, intervals[i].end >= v
    int search(vector<Interval> &intervals, int v) {
        int low = 0, high = intervals.size() - 1, mid;
        while(low < high) {
            mid = low + (high - low) / 2;
            if(intervals[mid].end > v) high = mid; //Chang into >= ??
            else if(intervals[mid].end == v) return mid;
            else low = mid + 1;
        }
        
        return intervals[high].end >= v ? high : high + 1;
    }
    
    bool InRange(int v, int below, int above) {
        return v >= below && v <= above;
    }
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> newIntervals;
        if(intervals.size() == 0) {
            newIntervals.push_back(newInterval);
            return newIntervals;
        }
        //Find the first intervals[i].end >= newInterval.start
        int left = search(intervals, newInterval.start);
        //Find the first intervals[i].end >= newInterval.end
        int right = search(intervals, newInterval.end);
        
        int n = intervals.size();
        bool leftInclu, rightInclu;
        
        if(left == n) {
            leftInclu = rightInclu = false;;
        }else if(right == n) {
            leftInclu = InRange(newInterval.start, intervals[left].start, intervals[left].end);
            rightInclu = false;
        }
        else {
            leftInclu = InRange(newInterval.start, intervals[left].start, intervals[left].end);
            rightInclu = InRange(newInterval.end, intervals[right].start, intervals[right].end);
        }
        
        copy(intervals.begin(), intervals.begin() + left, back_inserter(newIntervals));
        if(leftInclu && rightInclu) {
            newIntervals.push_back(Interval(intervals[left].start, intervals[right].end));
        }
        else if(leftInclu && !rightInclu) {
            newIntervals.push_back(Interval(intervals[left].start, newInterval.end));
            if(right != n) {
                newIntervals.push_back(intervals[right]);
            }
        }
        else if(!leftInclu && rightInclu) {
            //newIntervals.push_back(intervals[left]); //Error
            newIntervals.push_back(Interval(newInterval.start, intervals[right].end));
        }
        else {
            newIntervals.push_back(newInterval);
	     if(right != n) newIntervals.push_back(intervals[right]); //Forget to add
        }
        //copy right + 1... end 
        
        if(right != n) {
            copy(intervals.begin() + right + 1, intervals.end(), back_inserter(newIntervals));
        }
        
        return newIntervals;
    }
};
// Accepted
