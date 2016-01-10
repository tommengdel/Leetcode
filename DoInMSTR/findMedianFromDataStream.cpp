
class cmp {
    public:
        bool operator() (const int a, const int b) {
            return a > b;
        }
};
class MedianFinder {
public:

    priority_queue<int, vector<int>, cmp> minQueue;
    priority_queue<int, vector<int>> maxQueue;

    // Adds a number into the data structure.
    void addNum(int num) {
        //assume minQueue.size >= maxQueue.size
        minQueue.push(num);
        
        //Make sure all element in minQueue bigger or equal than maxQueue
        if(maxQueue.size() != 0 && maxQueue.top() > minQueue.top()) {
            int m1 = maxQueue.top(), m2 = minQueue.top();
            maxQueue.pop(); minQueue.pop();
            maxQueue.push(m2); minQueue.push(m1);
        }
        
        //Balance the two queue
        if(minQueue.size() > maxQueue.size() + 1) {
            maxQueue.push(minQueue.top());
            minQueue.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        //Compare the two queue size
        if(minQueue.size() == maxQueue.size()) {
            if(minQueue.size() != 0) {
                return (minQueue.top() + maxQueue.top()) / 2.0;
            } else return 0;
        } else {
          return minQueue.top();   
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();