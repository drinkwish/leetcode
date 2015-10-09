//0ms, fast enough

class Solution {
public:
    bool isValid(string s) {
        if((s.length())%2) return false;
        
        for(string::const_iterator iter = s.begin(); iter != s.end(); ++iter){
            if(*iter == '{' || *iter == '[' || *iter == '('){
                _stack.push_back(*iter);
            }
            else{
                if(_stack.size() == 0) return false;
                
                switch(*iter){
                    case '}':
                        if(_stack.back() == '{'){
                            _stack.pop_back();
                        }
                        else{
                            return false;
                        }
                        break;
                    case ']':
                        if(_stack.back() == '['){
                            _stack.pop_back();
                        }
                        else{
                            return false;
                        }
                        break;
                    case ')':
                        if(_stack.back() == '('){
                            _stack.pop_back();
                        }
                        else{
                            return false;
                        }
                        break;
                }
            }
        }
        
        if(_stack.size() == 0) return true;
        else return false;
        
    }
    
private:
    deque<char> _stack;
};