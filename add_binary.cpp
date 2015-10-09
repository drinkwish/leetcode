//4ms, fast enough

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() == 0)  return b;
        if(b.size() == 0) return a;
        
        char c= '0';
        int i_ = a.size();
        int j_ = b.size();
        
        string ret;
        while(i_ || j_){
            char c1;
            char c2;
            if(i_ > 0) {c1 = a[--i_];}
            else {c1 = '0';}
            
            if(j_ > 0) {c2 = b[--j_];}
            else {c2 = '0';}
            
            char tmp1 = xorOp(c1, c2);
            char tmp2 = andOp(c1, c2);
            char sum = xorOp(tmp1, c);
            c = orOp(tmp2, andOp(c, tmp1));
            ret = sum + ret;
        }
        
        if(c =='1') ret = "1" + ret;
        
        return ret;
    }
    
private:
    char xorOp(char a, char b){
        return a==b ? '0' : '1';
    }
    
    char andOp(char a, char b){
        return a == '1' && b == '1' ? '1' : '0';
    }
    
    char orOp(char a, char b){
        return a == '0' && b == '0' ? '0' : '1';
    }
};