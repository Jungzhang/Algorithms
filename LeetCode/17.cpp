/*************************************************************************
	> File Name: 17.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月14日 星期四 16时17分27秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        //将手机的每个按键映射到以数字键为下标的数组中
        std::vector<std::string> phoneMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        const int size = digits.size();
        std::vector<std::string> tmp(size);   //将数字字符串替换成每个数字键上的字母
        
        if (size == 0) {
            return result;
        }
        
        for (int i = 0; i < size; ++i) {
            if (digits[i] == '0' || digits[i] == '1') {
                return result;
            }
            tmp[i] = phoneMap[digits[i] - '0'];
        }
        
        func(result, digits, tmp, size, 0);
        
        return result;
    }
private:
    void func(std::vector<std::string> &result, std::string &tar, std::vector<std::string> &tmp,const int &len, int pos)
    {
        if (pos == len) {
            result.push_back(tar);  //如果到最后一层了则将其压入结果vector
            return;
        }
        for (int i = 0; i < tmp[pos].size(); ++i) {
            tar[pos] = tmp[pos][i]; 
            func(result, tar, tmp, len, pos + 1);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    s.letterCombinations("12");
    
    return EXIT_SUCCESS;
}
