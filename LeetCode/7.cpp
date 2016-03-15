/*************************************************************************
	> File Name: 7.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月04日 星期一 16时52分43秒
	> Description: 反向输出一个整数,如：123--->321   -123--->-321
    考虑反向之后会不会溢出
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        long result = 0;
        
        while (x) {
            result = result * 10 + (x % 10);
            x /= 10;
        }
        
        if (result > INT_MAX || result < INT_MIN) {
            return 0;
        }
        
        return result;
    }
};

int main(int argc, char *argv[])
{
    int i;
    std::cin >> i;
    Solution s;

   // std::cout << "1534236469" << "    " << INT_MAX << std::endl;
    std::cout << s.reverse(i) << std::endl;
    
    return EXIT_SUCCESS;
}
