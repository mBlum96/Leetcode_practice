//we create a stack and push if we get an open bracket and pop if we get a legal closing bracket

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> map;
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';


        stack<char> stack;
        stack.push('@');
        for(int i=0;i<s.length();i++){
            if(map.find(s[i])!=map.end()){
                if(stack.top()!=map.at(s[i])){
                    return false;
                }else{
                    stack.pop();
                }
           }else{
                stack.push(s[i]);
            }
            
        }
        if(stack.top()=='@')return true;
        return false;
    }
};