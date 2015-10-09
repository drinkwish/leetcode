//84ms, can be optimized
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int reverse_x=0;
        int tmp = x;
        while(tmp > 9){
            reverse_x = reverse_x*10 + tmp%10;
            tmp = tmp/10;
        }
        
        reverse_x = reverse_x*10 + tmp%10;
        
        return reverse_x == x;
    }
};