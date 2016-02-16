
class LRUCache{
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    list<pair<int, int>> mem;
    int capacity;

    void moveToFront(list<pair<int, int>> &mem,  list<pair<int, int>>::iterator front) {
        if(front != mem.begin()) {
            mem.splice(mem.begin(), mem, front, std::next(front));
        }
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        mem.clear();
        hash.clear();
    }

    int get(int key) {
        auto it = hash.find(key);
        if (it == hash.end()) return -1;
        else {
            //move it to front
            moveToFront(mem, it->second);
            hash[key] = mem.begin();
            return mem.begin()->second;
        }
    }

    void set(int key, int value) {
        //test the capacity
        auto it = hash.find(key);
        if(it != hash.end()) {
            it->second->second = value;
            moveToFront(mem, it->second);
            hash[key] = mem.begin();
        }
        else {
            if(mem.size() == capacity) {
                //remove the last element
                auto lastElement = mem.back();
                int abandonkey = lastElement.first;
                hash.erase(abandonkey);
                mem.erase(--mem.end());
            }
            //insert the element
            mem.emplace_front(key, value);
            hash[key] = mem.begin();
        }
    }
};
