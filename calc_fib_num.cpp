#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n==2){
            return 1;
        }
        else{
            return (n + fib(n-1));
        }
    }
};

int main(){
    int n = 3;
    Solution sol;
    cout << sol.fib(n) << endl;
    return 0;
}