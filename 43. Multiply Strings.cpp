#include <string>
#include <math.h>

using std::string;

string multiplier(char c, string num, int numLen){
    string sum;
    for(int i=0;i<numLen;i++){
        sum.push_back(c*num[i]*pow(10,i));
    }
    return sum;
}

class Solution {
public:
    string multiply(string num1, string num2) {
        string sum;
        for(char c : num1){
            sum += (multiplier(c,num2,num2.length()));
        }
        return sum;
    }
};