//8ms
//concept: digital root
//ref:https://en.wikipedia.org/wiki/Digital_root

class Solution {
public:
    int addDigits(int num) {
        if(num <= 0) return 0;
        if(num < 10) return num;
        return num-9*((num-1)/9);
    }
};

//20ms
class Solution {
public:
    int addDigits(int num) {
        if(num <= 0) return 0;
        if(num < 10) return num;
        int ret = num%9;
        if(ret == 0) return 9;
        else return ret;
    }
};