/*************************************************************************
	> File Name: 9.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月05日 星期二 20时12分25秒
	> Description: 判断一个数是不是回文数
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <climits>

class Solution {
public:
    bool isPalindrome(int x) {
        int t = x, flag;
        long tmp = 0; //防止int型溢出
        
        if (x < 0) {
            return false;
        }
        
        while (t) {
            tmp = tmp * 10 + (t % 10);
            t /= 10;
        }
        if (tmp == x) {
            return true;
        } else{
            return false;
        }
    }
};

int main(int argc, char *argv[])
{
    int a;
    Solution s;
    std::cin >> a;
    std::cout << s.isPalindrome(a) << std::endl;
    std::cout << INT_MAX << std::endl;
    
    return EXIT_SUCCESS;
}
