class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (heap_max.size() == 0 || heap_max.top() > num) {
            heap_max.push(num);
        } else {
            heap_min.push(num);
        }

        int n1 = (heap_max.size() + heap_min.size() + 1) / 2;

        if (n1 == heap_max.size()) return ;

        if (n1 < heap_max.size()) {
            heap_min.push(heap_max.top());
            heap_max.pop();
        } else {
            heap_max.push(heap_min.top());
            heap_min.pop();
        }
        return ;
    }
    
    double findMedian() {
        if ((heap_max.size() + heap_min.size()) % 2) {
            return heap_max.top();
        }
        double mindle_val_ = (heap_max.top() + heap_min.top()) / 2.0;
        return mindle_val_;
    }
private :
    priority_queue<int, vector<int>, greater<int> > heap_min;
    priority_queue<int, vector<int> > heap_max;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
