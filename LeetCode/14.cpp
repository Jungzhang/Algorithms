/*************************************************************************
	> File Name: 14.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月10日 星期日 13时33分12秒
	> Description: 给定一个字符串数组,求字符串数组中的最长公共前缀子串。
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        
        //如果为空,直接返回空字符串
        if (strs.size() == 0) {
            return "";
        }
        
        std::string result = "";
        
        //寻找最小长度的字符串,防止越界
        auto minSize = strs[0].size();
        for (auto &a : strs) {
            if (a.size() < minSize) {
                minSize = a.size();
            }
        }
        
        //以最小长度的字符串为外循环(因为最长的公共前缀不会长于最小长度的字符串)
        //每次检查所有的字符串是否相等
        for (int i = 0; i < minSize; ++i) {
            for (int j = 0; j + 1 < strs.size(); ++j) {
                if (strs[j][i] != strs[j + 1][i]) { //如果有一个不相等则已经没有必要再检查下去
                    return result;
                }
            }
            result += strs[0][i]; //如果都相等则将本次扫描的字符加在结果串上
        }
        
        return result;
    }
};

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
