/*************************************************************************
	> File Name: 13.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月09日 星期六 16时09分57秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <map>

/*class Solution {
public:
    int romanToInt(std::string s) {
        int result = 0;
        int pos = s.size() - 1;
        //建表
        std::map<std::string, int> romanNums = {
            {"I", 1}, {"V", 5} , {"IV", 4}, {"IX", 9}, {"X", 10}, 
            {"L", 50}, {"XL", 40}, {"XC", 90}, {"XC", 90}, {"C", 100}, 
            {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}
        };
        
        if (pos < 0) {
            return 0;
        }
        auto pre = romanNums.find(s.substr(pos, 1));
        std::map<std::string, int>::iterator tmp;
        while (pos >= 0) {
            auto now = romanNums.find(s.substr(pos, 1)); //查找对应的数字
            result += now->second;  //加到结果上
            if ((tmp = romanNums.find(now->first + pre->first)) != romanNums.end()) { //和前一个遍历的合起来是不是一个组合
                result = result - (now->second + pre->second - tmp->second);    //如果是组合,则删除多加的
            }
            pre = now; 
            --pos;
        }
        return result;
    }
};*/
/*
class Solution {
public:
    int romanToInt(std::string s) {
        int result = 0;
        if (s.empty()) {
            return 0;
        }
        std::map<char, int> romanNums = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size()) {
                if (romanNums.find(s[i])->second < romanNums.find(s[i + 1])->second) {
                    result -= romanNums.find(s[i])->second;
                } else {
                    result += romanNums.find(s[i])->second;
                }
            } else {
                result += romanNums.find(s[i])->second;
            }
        }
        
        return result;
    }
};*/

class Solution {
public:
    int romanToInt(std::string s) {
        int result = 0;
        if (s.empty()) {
            return 0;
        }
        
        int romanNums[89];
        romanNums['I'] = 1;    romanNums['V'] = 5;    romanNums['X'] = 10;
        romanNums['L'] = 50;   romanNums['C'] = 100;  romanNums['D'] = 500;
        romanNums['M'] = 1000;
        
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size()) {
                if (romanNums[s[i]] < romanNums[s[i + 1]]) {
                    result -= romanNums[s[i]];
                } else {
                    result += romanNums[s[i]];
                }
            } else {
                result += romanNums[s[i]];
            }
        }
        
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    std::cout << s.romanToInt("DCXXI") << std::endl;
    
    return EXIT_SUCCESS;
}
