/*************************************************************************
	> File Name: Factorial.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月24日 星期四 17时05分55秒
	> Description: 递归阶乘
 ************************************************************************/
#include <iostream>
#include <cstdlib>

int Factorial(int n)
{
    if (n == 1) {
        return 1;
    } else {
        return Factorial(n - 1) * n;
    }
}

int main(int argc, char *argv[])
{
    int n;

    std::cin >> n;

    std::cout << Factorial(n) << std::endl;
    
    return EXIT_SUCCESS;
}
