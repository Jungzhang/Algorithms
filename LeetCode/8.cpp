/*************************************************************************
	> File Name: 8.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月04日 星期一 22时59分50秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <climits>

/*
class Solution {
public:
    int myAtoi(std::string str) {
        long result = 0;
        bool flag = false;
        int i = 0, j;
        
        while(str[i] == ' ') {
            ++i;
        }
        
        if (str.size() <= 0) {
            return 0;
        } else if (str[i] == '-') {
            flag = true;
            ++i;
        } else if (str[i] == '+') {
            ++i;
        }
        
        j = i;
        
        if (!('0' <= str[i] && str[i] <= '9')) {
            return 0;
        }
        
        for (; i < str.size(); ++i) {
            if ('0' <= str[i] && str[i] <= '9') {
                result = result * 10 + (str[i] - '0');
            } else {
                if (flag) {
                    result *= -1;
                }
                if (result > INT_MAX) {
                    return INT_MAX;
                } else if (result < INT_MIN) {
                    return INT_MIN;
                }
        if (i - j > 10 && flag == false) {
            return INT_MAX;
        } else if (i - j > 10 && flag) {
            return INT_MIN;
        }
                return result;
            }
        }
        
        if (flag) {
            result *= -1;
        }
        if (i - j > 10 && flag == false) {
            return INT_MAX;
        } else if (i - j > 10 && flag) {
            return INT_MIN;
        }
        if (result > INT_MAX) {
            return INT_MAX;    
        } else if (result < INT_MIN) {
            return INT_MIN;
        }
        
        
        return result;
    }
}; */

class Solution {
public:
    int myAtoi(std::string str) {
        
        int ret = 0, tmp;
        int i = 0, flag = 1;
        int len = str.length();
        
        //防止输入的是空字符串
        if (len == 0) {
            return 0;
        }
        
        //去掉输入字符串前边的空格
        while (str[i] == ' ') {
            i++;
        }
        
        //判断输入的是正数还是负数
        if (str[i] == '-') {
            i++;
            flag = -1;
        }
        else if (str[i] == '+') {
            i++;
        }
        
        //循环转换每一个元素
        for (;i < len; i++) {
            //保证每个数字都合法
            if (str[i] < '0' || str[i] > '9') {
                break;
            }
            
            tmp = ret * 10 + str[i] - '0';  //将本次转换结果先存入一个临时变量
            
            //判断是否越界
            //因为一个数乘以10之后越界,再除以10不等于原数,根据这条性质就可以判断是否越界
            if (tmp / 10 != ret) {
                if (flag == 1) {
                    return INT_MAX;
                }
                else { 
                    return INT_MIN;
                }
            }
            ret = tmp;
        }
        
        return ret * flag;
    }
};

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
