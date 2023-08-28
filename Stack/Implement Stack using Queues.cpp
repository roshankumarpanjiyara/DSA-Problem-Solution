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
