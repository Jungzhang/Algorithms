/*************************************************************************
	> File Name: 5.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月02日 星期六 22时00分35秒
	> Description: 求给定字符串中的最长回文子串,"马拉车"算法
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>

//暴力求解法,时间复杂度为O(n^3)
/*class Solution {
public:
    std::string longestPalindrome(std::string s) {
        bool flag;
        std::string::size_type start = 0, end = 0;
        
        for (std::string::size_type i = 0; i < s.size(); ++i) {
            for (std::string::size_type j = i; j < s.size(); ++j) {
                std::string result = s.substr(i, j - i + 1);
                flag = true;
                for (std::string::size_type k = 0; k <= result.size() / 2; ++k) {
                    if (result[k] != result[result.size() - k - 1]) {
                        flag = false;
                        break;
                    }
                }
                if (flag && (j - i + 1 > end - start)) {
                    start = i; end = j + 1;
                }
            }
        }
        
        return s.substr(start, end - start);
    }
}; */

//"马拉车"算法,时间复杂度为O(n)
class Solution {
public :
    std::string longestPalindrome(std::string s) {
        int maxpos = 0, mid = 0;
        std::vector<int> v;
        int max = 0;
        std::string tmp = s;
        init(tmp);
        v.resize(tmp.size());
        for (int i = 0; i < tmp.size(); ++i) {
            //如果可以直接从以前计算过的里边取出值
            if (i < maxpos) {
                v[i] = v[mid * 2 - i] < (maxpos - i) ? v[mid * 2 - i] : (maxpos - i);
            } else {    //不能直接从以前计算过的里边取值
                v[i] = 1;
            }
            //向两遍扩展,寻找以i为中心最长的
            while(i - v[i] >= 0 && i + v[i] < tmp.size() && tmp[i - v[i]] == tmp[i + v[i]]) {
                ++v[i];
            }
            //记录v中最大值的下标,便于函数的最后返回子串
            if (v[i] >= v[max]) {
                max = i;
            }
            //更新最大位置和中间位置
            if (v[i] + i > maxpos) {
                maxpos = v[i] + i;
                mid = i;
            }
        }
        int i, j;
        //如果max为奇数则表示前边加了v[max]/2+1个#
        if (max % 2) {
            i = max / 2 - v[max] / 2 + 1;
        } else {  //max为偶数则表示加了v[max]/2个#
            i = max / 2 - v[max] / 2;
        }
        //v中存储的是预处理后的字符串,减一后表示原字符串的最大回文
        j = v[max] - 1;
        
        return s.substr(i,j);
    }
private:
    void init(std::string &s)
    {
        s.resize(s.size() * 2 + 1);
        for (auto i = s.size() - 1; i != 0; i = i - 2) {
            s[i] = '#';
            s[i - 1] = s[(i - 1) / 2];
        }
        s[0] = '#';
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    std::string a = "adam";
    std::cout << s.longestPalindrome(a) << std::endl;
    
    return EXIT_SUCCESS;
}
