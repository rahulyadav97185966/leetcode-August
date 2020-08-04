//Power of Four

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 0)
            return false;
        return floor(logn(num,4))==ceil(logn(num,4));
    }
    float logn(int n,int r){
        return log(n)/log(r);
    }
};
