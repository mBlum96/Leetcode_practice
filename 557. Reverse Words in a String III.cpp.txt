class Solution {
public:
    string reverseWords(string s) {
        int find_white_space = 0;
        int r_ptr = 0;
        while(r_ptr<s.size()){
            if((s[find_white_space]!=' ') && (s[find_white_space] != '\0')){
                find_white_space++;
            }
            else{
                for(int i=0;i<(find_white_space - r_ptr -i);i++){
                    char temp = s[find_white_space-i-1];
                    s[find_white_space-i-1] = s[r_ptr+i];
                    s[r_ptr+i] = temp; 
                }
                r_ptr = find_white_space + 1;
                find_white_space++;
            }
        }
        return s;
    }
};
