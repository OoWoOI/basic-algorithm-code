class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : K_(k) {
        for (auto x : nums) {
            add(x);
        }
    }
    
    int add(int val) {
        if (min_heap.size() < K_) {
            min_heap.push(val);
        } else if (val > min_heap.top()) {
            min_heap.pop();
            min_heap.push(val);
        }
        return min_heap.top();
    }
private :
    int K_;//第K大
    priority_queue<int, vector<int>, greater<int> > min_heap;//小顶堆
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
