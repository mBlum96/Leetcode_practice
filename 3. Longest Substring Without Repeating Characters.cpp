#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int right = 0;
        int abcLen = 'z'-'a';
        vector<int>  charDict(abcLen, -1);
       
        if(s2.size()<s1.size()){
            return false;
        }
        for(int i=0;i<s1.size();i++){
            if(charDict[s1[i]]!=-1){
                charDict[s1[i]]++;
            }
            else{
                charDict[s1[i]]=1;
            }
        }
        while(right<s2.size()){
            right = left + s1.size() -1;
            bool are_all_in_s1 = true;
            if(charDict[s2[right]]==-1){//this is an optimization
                left++;
                continue;
            }
            for(int i=0;i<(s1.size()-1);i++){//the minus one is because
            // of the if in line 23
                if(charDict[s2[left+i]]==-1){
                    are_all_in_s1 = false;
                    break;
                }
            }
            if(are_all_in_s1==false){
                left+=i;
            }
            else{
                for(int j=0;j<s1.size();j++){//here I want to check that 
                //all the numbers in the window are in s1, let's say that in
                // the window we have 'aaa' but in s1 it's 'aab' then we do
                // have all the values of the window in s1 but still it is not
                // a permutation because it lacks 'b'/
                    if
                }
            }
        }
       
       
        return false;
    }
};
