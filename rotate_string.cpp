
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void reverseString(string s) {
        int r_ptr = s.size()-1;
        int l_ptr = 0;
        while (r_ptr>l_ptr){
            char temp = s[r_ptr];
            s[r_ptr--] = s[l_ptr];
            s[l_ptr++] = temp;
        }
    }

    bool rotateString(string s, string goal) {
        if(s.compare(goal)){
            return true;
        }
        if(s.length()!= goal.length()){
            return false;
        }

        int s_len = s.length();
        int i = 0;
        while (i<s_len){
            reverseString(s);
            if(s.compare(goal)){
                return true;
            }
            i++;
        }
        return false;

    }
};