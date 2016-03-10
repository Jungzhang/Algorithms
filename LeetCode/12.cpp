/*************************************************************************
	> File Name: 12.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月09日 星期六 14时28分09秒
	> Description: 将数字转换为罗马数字,范围是1-3999
 ************************************************************************/
#include <iostream>
#include <cstdlib>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string result = "";
        std::string romanNums[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };
        
        //取出前三位的数字
        for (int i = 1000, j = 3; i != 1; i /= 10, --j) {
            result += romanNums[j][num / i % 10];
        }
        //取出最后一位的数字
        result += romanNums[0][num % 10];
        
        return result;
    }
};

int main(int argc, char *argv[])
{
    int num;

    std::cin >> num;

    Solution s;
    std::cout << s.intToRoman(num) << std::endl;
    
    return EXIT_SUCCESS;
}
