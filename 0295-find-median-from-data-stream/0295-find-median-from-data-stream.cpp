class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int curr_size;
    MedianFinder() {
        curr_size = 0;
    }
    
    void addNum(int num) {
        //decide to which heap it will go
        if (maxheap.empty() || maxheap.top() >= num){
            maxheap.push(num);
        } else minheap.push(num);

        //balancing
        //rule broken
        if (maxheap.size() > minheap.size() + 1){
            //maxheap to minheap
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if (minheap.size() > maxheap.size()){
            //minheap to maxheap
            maxheap.push(minheap.top());
            minheap.pop();
        }
        curr_size++;
    }
    
    double findMedian() {
        if (curr_size % 2 == 1){
            return maxheap.top();
        }
        double median = (maxheap.top() + minheap.top())/2.0;
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */