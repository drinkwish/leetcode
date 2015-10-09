//0ms fast enough
class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        if(n < 1) return ret;
        
        while(n>0){
            if(n%26 == 0) ret = "Z" + ret;
            else{
                string tmpStr = "A";
                tmpStr[0] += n%26 -1;
                ret = tmpStr + ret;
                
            }
            n = (n-1)/26;
        }
        
        return ret;
            
        
    }
};