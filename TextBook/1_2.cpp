/*************************************************************************
	> File Name: 1_2.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月07日 星期一 19时08分37秒
	> Description: 字典序问题,给定一个长度不超过6的小写字母升序字符串(字符
    串中的字符相对顺序和字母表中的顺序一致),迅速计算出在字典中的编码,字典如：
    1   2   3   ...     26  27  28  ...
    a   b   c   ...     z   ab  ac  ...
 ************************************************************************/
#include <iostream>
#include <cstdlib>

//计算从i开始的长度为k的所有数的个数
//例如以a开头长度为2的所有组合个数
int CharacterCount(int i, int k)
{
    int sum = 0;
    
    if (k == 1) {
        sum = 1;
    } else  {
        //以i开头的长度为k的字符串的个数等于CharacterCount(m,k - 1)的和 //m是一个i+1到26的闭区间
        for (int j = i + 1; j <= 26; ++j) {
            sum += CharacterCount(j, k - 1);
        }
    }

    return sum;
}

//计算长度为k的字符串的所有组合的总和个数
//例如以a开头,长度为2的所有组合的总和个数等于长度为2的加上长度为1的
int CharacterSumCount(int k)
{
    int sum = 0;
    //总和等于所有长度小于k的字符串组合之和
    for (int i = 1; i <= 26; ++i) {
        sum += CharacterCount(i, k);
    }

    return sum;
}

//总体思路为先计算出给定字符串前所有的个数再加一
int FindCode(std::string &str)
{
    int code = 0; //保存最终结果
    auto len = str.size();

    //计算1~len-1的所有总和
    for (int i = 1; i < len; ++i) {
        code += CharacterSumCount(i);
    }

    //小于第一个字母的长度为k的所有组合
    for (int i = 1; i < str[0] - 96; ++i) {
        code += CharacterCount(i, len);
    }

    //以第一个字母作为开始字符的字符串组合总个数
    for (int i = 1; i < str.size(); ++i) {
        for (int j = str[i - 1] - 96 + 1; j < str[i] - 96; ++j) {
            code += CharacterCount(j, str.size() - i);
        }
    }
    
    return code + 1;  //前面代码求出了给定字符串前所有的个数,加1就是给定字符串的编码
}

int main(int argc, char *argv[])
{
    std::string str;
    std::cin >> str;
    
    if (str.size() > 6) {
        std::cerr << "输入的字符串超过长度限制" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << FindCode(str) << std::endl;
    
    return EXIT_SUCCESS;
}
