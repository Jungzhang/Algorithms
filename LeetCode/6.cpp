/*************************************************************************
	> File Name: 6.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月03日 星期日 22时59分25秒
	> Description: LeetCode第6题,将字符串按照睡着的s型输出
 ************************************************************************/
#include <iostream>
#include <cstdlib>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        std::string result = "";
        int tmp, off = numRows * 2 - 2;     //固定偏移量(N字主干部分节点)
        if (numRows >= s.size() || numRows == 1) {
            return s;
        }
        
        for (int i = 1; i <= numRows; ++i) {
            result += s[i - 1];
            if (i == numRows){
                tmp = 0; //特殊处理最后一行
            } else{ 
                tmp = (i - 1) * 2;  //中间孤零零的节点
            }
            for (int j = 1; off * j + i - 1 - tmp < s.size(); ++j) {
                if (tmp) {
                    result = result + s[off * j + i - 1 - tmp];  //N字主干部分
                }
                if (off * j + i - 1 < s.size()) {
                    result = result + s[off * j + i - 1];  //孤零零的中间节
                }
            }
        }
        
        return result;
    }
};

int main(int argc, char *argv[])
{
    std::string a = "ABCD";
    Solution s;
    std::cout << s.convert(a, 3) << std::endl;
    
    return EXIT_SUCCESS;
}
