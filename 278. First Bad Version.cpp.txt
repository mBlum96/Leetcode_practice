// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        double latest_ver = n;
        double first_ver = 1;
        int mid_ver = (first_ver + latest_ver)/2;
        int first_bad;
        while(true){
            if(isBadVersion(mid_ver)){
                first_bad = mid_ver;
                latest_ver = mid_ver-1;
            }
            else{
                first_ver = mid_ver+1;
            }
            mid_ver = (first_ver + latest_ver)/2;
            if(first_ver>latest_ver){
                return first_bad;
            }
        }
    }
};
