class Solution {
public:
    void reverseString(vector<char>& s) {
        int r_ptr = s.size()-1;
        int l_ptr = 0;
        while (r_ptr>l_ptr){
            char temp = s[r_ptr];
            s[r_ptr--] = s[l_ptr];
            s[l_ptr++] = temp;
        }
    }
};
