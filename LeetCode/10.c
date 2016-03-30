/*************************************************************************
	> File Name: 10.c
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月07日 星期四 15时44分24秒
	> Description: LeetCode第十题,正则的匹配之 . 和 *
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int isMatch(char *s, char *p)
{
    //递归出口判断
    if (p[0] == '\0') {
        return s[0] == '\0';
    }

    //分情况解决匹配问题,一种带*一种不带*
    if (p[1] == '*') { //带*
        while (s[0] != '\0' && (p[0] == '.' || s[0] == p[0])) { //如果匹配成功
            if (isMatch(s, p + 2)) { //先把带*的匹配掠过,对后边的进行匹配
                return 1;
            }
            ++s;    //把s向后移动一位,然后再次匹配*前的元素(因为*前的元素可能出现多次)
        }
        return isMatch(s, p + 2);   //继续匹配剩下的
    } else {  //不带*
        //如果匹配成功
        if (s[0] != '\0' && (p[0] == '.' || s[0] == p[0])) {
            return isMatch(s + 1, p + 1);   //递归下一个元素匹配
        } else { //没有匹配成功
            return 0;
        }
    }
    
}

int main(int argc, char *argv[])
{
    
    
    return EXIT_SUCCESS;
}
