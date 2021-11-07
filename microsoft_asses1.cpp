#include <iostream>
// you can use includes, for example:
// #include <algorithm>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(int A, int B, int C) {
    // write your code in C++14 (g++ 6.2.0)
    int aCounter = 0;
    int bCounter = 0;
    int cCounter = 0;

    int totLen = A+B+C;
    int i = 0;
    string result;

    for (size_t i = 0; i < totLen; i++){
        if(A>0 && ((aCounter<2 && A>=B && A>=C)||(bCounter==2||cCounter==2))){
            result.push_back('a');
            aCounter++;
            bCounter = 0;
            cCounter = 0;
            A--;
        }
        else if(B>0 && ((bCounter<2 && B>=A && B>=C)||(aCounter==2||cCounter==2))){
            result.push_back('b');
            bCounter++;
            aCounter = 0;
            cCounter = 0;
            B--;
        }
        else if(C>0 && ((cCounter<2 && C>=B && C>=A)||(aCounter==2||bCounter==2))){
            result.push_back('c');
            cCounter++;
            aCounter = 0;
            bCounter = 0;
            C--;
        }
    }
    return result;
}

int main(){
    int A = 0;
    int B = 1;
    int C = 8;
    string result = solution(A,B,C);
    return 0;
}