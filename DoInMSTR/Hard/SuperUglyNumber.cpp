class Solution {
  class Node {
  public:
    int index;
    int value;

    Node(int i, int v) : index(i), value(v) {}
  };

  class cmp {
  public:
    // bool operator()(const node& n1, const node &n2) {
     bool operator()(const Node& n1, const Node&n2) {
      return n1.value > n2.value;
    }
  };


public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) return 1;
        vector<list<int>> numList(primes.size());
        sort(primes.begin(), primes.end());
        vector<int> upper_limit(primes.size());

        //set upper limit
        //init list
        for(int i = 0; i < primes.size(); ++i) {
           upper_limit[i] = INT_MAX / primes[i];
           numList[i].push_back(primes[i]);
         }

         priority_queue<Node, vector<Node>, cmp> pq;
         //init pq
         for(int i = 0; i < numList.size(); ++i) {
           pq.emplace(i, numList[i].front());
           numList[i].pop_front();
         }

         //fetch element

         for(int i = 1; i < n - 1; ++i) {
            const  Node &topNode = pq.top(); pq.pop();
            //fill the list topNode.index
            for(int i1 = 0; i1 <= topNode.index; ++i1) {
               if(topNode.value > upper_limit[i1]) break;
               numList[topNode.index].push_back(topNode.value * primes[i1]);
            }

            //push new node
            if(!numList[topNode.index].empty()) {
              pq.emplace(topNode.index, numList[topNode.index].front());
              numList[topNode.index].pop_front();
            }
         }

         return pq.top().value;
    }
};
//Error case
//4
// [2,3,5]
