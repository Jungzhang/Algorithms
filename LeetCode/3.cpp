/*************************************************************************
	> File Name: 3.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月28日 星期一 16时41分34秒
	> Description: 给定一个字符串.求字符串的最长不重复子序列的长度
    如:abcabcbb的最长不重复子序列是abc,长度是:3   bbbbb的最长不重复子序列
    是b,长度是1
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

class Solution {
public :
    int lengthOfLongestSubstring(std::string s) 
    {
        int length = 0;     //最终长度
        int tmp = 0;    //目前扫描长度
        std::vector<char> v;    //记录扫描过的点
        std::vector<int> pos;   //对应记录扫描过的点的下标
        
        for (auto i = 0; i != s.size(); ++i) {
            auto b = std::find(v.begin(), v.end(), s[i]);   //查找是否已经走过
            if (b != v.end()) { //如果找到
                if (tmp > length) { //并且当前值大于已记录的最大值
                    length = tmp;   //修改记录的最大值
                } 
                tmp = (i - *(pos.begin() + (b - v.begin())));   //重新计算当前值的大小
                v.erase(v.begin(), b + 1);  //删除值记录中的相应数字
                pos.erase(pos.begin(), (pos.begin() + (b - v.begin()) + 1));    //删除值记录对应的下标
            } else {
                ++tmp;  //如果没有重复则当前记录值自增
            }
            
            v.push_back(s[i]);  //将扫描过的值加入集合
            pos.push_back(i);   //将对应下标加入集合
            
            //如果循环结束后扫描值比记录值大,则修改记录值
            if (i == s.size() - 1 && length < tmp) {
                length = tmp;   
            }
        }
        
        return length;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    std::cout << s.lengthOfLongestSubstring("vqblqcb") << std::endl;
    
    return EXIT_SUCCESS;
}
