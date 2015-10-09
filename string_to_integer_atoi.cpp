//12ms, can be optimized

class Solution {
public:
    int myAtoi(string str) {
        return myAtoiAlg(str, 0);
    }
    
private:
    int myAtoiAlg(string str, const int start) {
        if(start == str.size()) return 0;
        if(str[start] == ' ') return myAtoiAlg(str, start+1);
        
        if(str.size() -start== 1 &&( str[start] > '9' || str[start] < '0')) return 0;
        
        bool sign;
        if(str[start] >= '0' && str[start] <= '9'){
            sign = true;
        }
        else if(str[start] == '+'){
            sign = true;
            str[start] = '0';
        }
        else if(str[start] == '-'){
            sign = false;
            str[start] = '0';
        } 
        else return 0;

        int ret = 0;
        if(sign){
            for(int i_ = start; i_< str.length(); ++i_){
                if(str[i_] <'0' || str[i_] > '9') return ret;
                if(sign && (int(0x7FFFFFFF) - str[i_] + '0')/10 <ret) return 0x7FFFFFFF;
                
                ret = ret*10 + str[i_] - '0';
            }
        }
        else{
            for(int i_ = start; i_< str.length(); ++i_){
                if(str[i_] <'0' || str[i_] > '9') return ret;
                if(!sign && (int(0x80000000) + str[i_] - '0')/10 >ret) return 0x80000000;
                
                ret = ret*10 - str[i_] + '0';
            }
        }
        
        return ret;
    }
};