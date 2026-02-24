// https://leetcode.com/problems/find-median-from-data-stream/description/
#include <set>


class MedianFinder {
private: 
    std::multiset<int> orderedNumbers_   ; 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        orderedNumbers_.insert(num);
    }
    
    double findMedian() {
        int size = orderedNumbers_.size();
        bool isPair = size%2==0;
        auto it = orderedNumbers_.begin();
        if (size == 1) {
            return *it;
        }
        if (isPair){
            int prev = *it;
            for(int i = 0; i< size/2;++i){
                prev = *it;
                it++;
            }
            return (prev + *it)/2.0;

        }else{
            for(int i = 0; i< size/2;++i){
                it++;
            }
            return *it;

        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */