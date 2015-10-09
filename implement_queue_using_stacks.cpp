class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s0.push_back(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(s1.empty()){
            while(!s0.empty()){
                int tmp = s0.back();
                s1.push_back(tmp);
                s0.pop_back();
            }
        }
        
        if(!s1.empty()){
            s1.pop_back();
        }
    }

    // Get the front element.
    int peek(void) {
        if(s1.empty()){
            while(!s0.empty()){
                int tmp = s0.back();
                s1.push_back(tmp);
                s0.pop_back();
            }
        }
        
        if(!s1.empty()){
            return s1.back();
        }
        
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s0.empty() && s1.empty();
        
    }

private:
    std::list<int> s0;
    std::list<int> s1;
};
