#include <string>
#include <cstring>

using namespace std;

class Solution {
public:



    string numberToWords(int num) {
        char *numbers[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        char *numberty[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        char *number_ten[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        char *level[] = {"", "Thousand", "Million", "Billion"};

        char numStr[105];
        sprintf(numStr, "%d", num);
        int n = strlen(numStr);
        char str[4];
        int nums[10];
        int numsCount=0;
        for (int i = n - 1; i >= 0; i-=3) {
            int start = i-2;
            int len = 3;
            if(start<0) {
                len+=start;
                start=0;
            }
            memcpy(str, numStr+start, len);
            str[len]=0;
//            puts(str);
            sscanf(str, "%d", &nums[numsCount++]);
        }
        string levelStr[10];
        for(int i =0;i<numsCount;i++) {
            printf("%d\n", nums[i]);
            levelStr[i]="";
            int tmp = nums[i];
            bool specify=false;
            if (tmp/100)
                levelStr[i]+=string(numbers[tmp/100]) + " Hundred";
            tmp%=100;
            if (tmp/10) {
                if(levelStr[i]!="")
                    levelStr[i] += " ";
                if(tmp/10==1) {
                    levelStr[i] += string(number_ten[tmp % 10]);
                    specify=true;
                }
                else {
                    levelStr[i] += string(numberty[tmp / 10]);
                }
            }
            tmp%=10;
            if (tmp && !specify) {
                if(levelStr[i]!="")
                    levelStr[i] += " ";
                levelStr[i] += string(numbers[tmp]);
            }
            if(levelStr[i]!="" && i !=0)
                levelStr[i]+=" "+string(level[i]);
        }
        string ans=levelStr[numsCount-1];
        for(int i =numsCount-2;i>=0;i--){
            if (levelStr[i]!="")
                ans+=" "+levelStr[i];
        }
        if (ans=="")return "Zero";
        return ans;
    };
};