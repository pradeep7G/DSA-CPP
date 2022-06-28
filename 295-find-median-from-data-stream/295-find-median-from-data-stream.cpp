class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    MedianFinder() {
        
    }
    void balance(){
        if(pq1.size()<pq2.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
        else if(pq2.size()+1 < pq1.size()){
            pq2.push(pq1.top());
            pq1.pop();
        }
    }
    void addNum(int num) {
        if(pq1.empty()){
            pq1.push(num);
        }
        else{
            if(pq1.top()>num){
                int top=pq1.top();
                pq1.pop();
                pq1.push(num);
                pq1.push(top);
                balance();
            }
            else{
                pq2.push(num);
                balance();
            }
        }
    }
    
    double findMedian() {
        int size=pq1.size()+pq2.size();
        if(size%2==0)
        {
            return (double)(pq1.top() + pq2.top())/(double)2;
        }
        else
            return pq1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */