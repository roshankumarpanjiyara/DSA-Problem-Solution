//approach 1
class MyStack {

    Queue<Integer> q1 = new LinkedList<>();
    Queue<Integer> q2 = new LinkedList<>();

    public MyStack() {
        
    }
    
    public void push(int x) {
        while(!q1.isEmpty()){
            q2.offer(q1.peek());
            q1.poll();
        }
        q1.offer(x);
        while(!q2.isEmpty()){
            q1.offer(q2.peek());
            q2.poll();
        }
    }
    
    public int pop() {
        int val = q1.peek();
        q1.poll();
        return val;
    }
    
    public int top() {
        return q1.peek();
    }
    
    public boolean empty() {
        return q1.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */


//approach 2
class MyQueue {
public:
    int front;
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()){
            front = x;
        }
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int tp =  s2.top();
        s2.pop();
        return tp;
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        return front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
