class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int l=0;
        int balance = 0, swaps = 0, r=n-1;
        
        while(r>l)
        {
            if(s[l] == '[') balance++;
            else balance--;

            if(balance < 0)
            {
                while(s[r] != '[') r--;
                swap(s[l], s[r]);
                swaps++;
                balance = 1;
            }
            l++;
        }
        return swaps;
    }
};
