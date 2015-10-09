//32ms, can be optimized

class MinStack {
public:
    void push(int x) {
        if(0 == _min.size() || x <= _min.back()){
            _min.push_back(x);
        }
        _s.push_back(x);
    }

    void pop() {
        if(_s.back() == _min.back()){
            _min.pop_back();
        }
        _s.pop_back();
    }

    int top() {
        return _s.back();
    }

    int getMin() {
        return _min.back();
    }
    
private:
    list<int> _s;
    list<int> _min;
};