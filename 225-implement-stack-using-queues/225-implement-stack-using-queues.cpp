class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
       queue<int> tmp;
       while(!q.empty()){
           tmp.push(q.front());
           q.pop();
       }
       q.push(x);
       while(!tmp.empty()){
           q.push(tmp.front());
           tmp.pop();
       }
    }
    
    int pop() {
        int data=q.front();
        q.pop();
        return data;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */