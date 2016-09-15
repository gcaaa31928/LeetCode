// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        bool end = false;
        int l = 1, r = n;
        while (l<r) {
            int guess_num = ((r-l) >> 1) + l;
            int res = guess(guess_num);
            if(res==0) return guess_num;
            else if (res==1){
                l=guess_num +1;
            }
            else if (res==-1) {
                r=guess_num-1;
            }
        }
        return r;
    }
};