#include <list>
#include <unordered_map>
using namespace std;
class LRUCache {
private:
// ID and value both ints 

std::list<std::pair<int,int>> cache_;
std::unordered_map<int, std::list<std::pair<int,int>>::iterator> map_;

int capacity_;
public:
    LRUCache(int capacity): capacity_(capacity){    }
    
    int get(int key) {
        auto it = map_.find(key);
            if (it != map_.end() ){
                cache_.splice(cache_.begin(), cache_, it->second);
                return it->second->second;
            }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = map_.find(key);
            if (it != map_.end()){
                it->second->second = value;
                cache_.splice(cache_.begin(), cache_, it->second);
                return;
            }

        if(cache_.size() == capacity_){
            auto last = cache_.back();
            map_.erase(last.first);
            cache_.pop_back();
        }
        cache_.push_front({key,value});
        map_[key]= cache_.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */