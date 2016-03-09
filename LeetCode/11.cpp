/*************************************************************************
	> File Name: 11.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月08日 星期五 16时08分16秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>

//暴力法
/*class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int pos, max = 0;
        for (int i = 0; i < height.size(); ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                int tmp = (height[i] < height[j] ? height[i] : height[j]) * (j - i);
                if (max < tmp) {
                    pos = i;
                    max = tmp;
                }
            }
        }
        
        return max;
    }
};

//暴力法的另一种写法
class Solution {
public:
    int maxArea(std::vector<int> &height) {
        int max = 0, start, end, tmp;
        long count = 0;
        for (int maxLen = height.size() - 1; maxLen > 0; --maxLen) {
            start = height.size() - 1;
            end = start - maxLen;
            while (end >= 0) {
                tmp = (height[start] < height[end] ? height[start] : height[end]) * maxLen;
                if (tmp > max) {
                    max = tmp;
                }
                ++count;
                --start;
                end = start - maxLen;
            }
        }
        std::cout << "count" << count << std::endl;
        
        return max;
    }
};*/

class Solution {
public:
    int maxArea(std::vector<int> &height) {
        int max = 0, i = 0, j = height.size() - 1, tmp = 0;
        
        while (i < j) {
            bool flag = height[i] < height[j] ? true : false;
            if (flag) {
                ++i;
                tmp = height[i] * (j - i);
            } else {
                --j;
                tmp  = height[j] * (j - i);
            }
            if (tmp > max) {
                max = tmp;
            }
        }
        
        return max;
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> a;
    Solution s;
    std::cout << s.maxArea(a) << std::endl;
    
    return EXIT_SUCCESS;
}
