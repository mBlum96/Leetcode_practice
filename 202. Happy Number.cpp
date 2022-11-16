int findSumSquared(int &target){
    int m=0;
    int result = 0;
    while(target>0){
        m = target%10;
        result += m*m;
        target /= 10;
    }
    return result;
}

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(1){
            slow = findSumSquared(slow);
            fast = findSumSquared(fast);
            fast = findSumSquared(fast);
            if(fast==slow)break;
        }
        if(slow==1)return true;
        return false;
    }
};