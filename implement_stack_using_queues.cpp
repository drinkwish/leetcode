class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push_back(x);
        int cnt = q.size();
        while(cnt-- > 1){
            int tmp = q.front();
            q.push_back(tmp);
            q.pop_front();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop_front();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
        
    }
    
private:
    std::list<int> q;
};
