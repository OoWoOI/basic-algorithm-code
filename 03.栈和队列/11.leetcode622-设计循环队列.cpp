class MyCircularQueue {
private:
    vector<int> *vec;
    int vec_size, vec_cnt, vec_head, vec_tail;
public:
    MyCircularQueue(int k) : 
        vec(new vector<int>(k)), 
        vec_size(k),
        vec_cnt(0),
        vec_head(0),
        vec_tail(0)
        {
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        (*vec)[vec_tail] = value;
        vec_tail = vec_tail + 1 == vec_size ? 0 : vec_tail + 1;
        vec_cnt++; 
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        vec_head = vec_head + 1 == vec_size ? 0 : vec_head + 1;
        vec_cnt--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return (*vec)[vec_head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        int ind = vec_tail - 1 < 0 ? vec_size - 1 : vec_tail - 1;
        return (*vec)[ind];
    }
    
    bool isEmpty() {
        return vec_cnt == 0;
    }
    
    bool isFull() {
        return vec_size == vec_cnt;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
