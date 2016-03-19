/*************************************************************************
	> File Name: 1_1.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月02日 星期三 18时26分42秒
	> Description: 给定一个数字number,求 1 到 number 之间有多少个 0 ~ 9
 ************************************************************************/
#include <iostream>
#include <cstdlib>

//暴力解法
void NumCount1(int number, int result[])
{
    for (int i = 1; i <= number; ++i) {
        int tmp = i;
        while (tmp != 0) {
            ++result[tmp % 10];
            tmp /= 10;
        }
    }
}

int main(int argc, char *argv[])
{
    int number;
    int result[10] = {0};

    std::cin >> number;

    NumCount1(number, result);

    for (auto a : result) {
        std::cout << a << std::endl;
    }
    
    return EXIT_SUCCESS;
}
