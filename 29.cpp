#include <climits>
#include <cstdlib>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;


        long long ans = 0;
        bool sign=false;
        if(dividend<0) {
            sign=!sign;
        }
        if(divisor<0) {
            sign=!sign;
        }

        long long divid=labs(dividend);
        long long divis=labs(divisor);
        if (divis == 1)return sign? -divid: divid;
        while(divid>=divis) {
            long long tmp = divis;
            long long sub=0;
            long long bit2 = 1;
            while(tmp<=divid) {
                sub = tmp;
                tmp <<= 1;
                bit2 <<= 1;
            }
            bit2>>=1;
            ans+=bit2;
            divid -= sub;
        }
        return sign? -ans: ans;
    }
};
