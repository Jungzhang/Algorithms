/*************************************************************************
	> File Name: CountBinary.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月25日 星期五 22时21分18秒
	> Description: 给定一个数字,返回其二进制中1的个数
 ************************************************************************/
#include <iostream>
#include <cstdlib>

//func1,直接移位加计数法
unsigned int func1(int num)
{
    unsigned int count;

    for (count = 0; num != 0; num >>= 1) {
        count += num & 1;
    }

    return count;
}

//func2,快速法,使用n & (n - 1)去掉最右边的1,直至n为0
//原理是n = (n - 1) + 1,所以和n - 1进行与运算之后会去掉一个1
unsigned int func2(int num)
{
    unsigned int count;

    for (count = 0; num; ++count) {
        num = num & (num - 1);      //n = (n - 1) + 1,所以和n - 1进行与运算之后会去掉一个1
    }

    return count;
}

int main(int argc, char *argv[])
{
    int num;

    std::cin >> num;
    std::cout << func1(num) << std::endl;
    std::cout << func2(num) << std::endl;
    
    return EXIT_SUCCESS;
}
