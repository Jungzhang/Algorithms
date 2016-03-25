/*************************************************************************
	> File Name: TriangleNumber.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月12日 星期二 19时31分18秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>

//递归+记忆法Lintcode 36ms
/*class Solution {
public:
    int longestOfPath(std::vector<std::vector<int>> &nums, int i, int j) {
        if (nums.size() == 0) {
            return 0;
        }
        
        std::vector<std::vector<int>> visited;
        for (auto &a : nums) {
            std::vector<int> tmp(a.size(), INT_MIN);
            visited.push_back(tmp);
        }
        
        return longestOfNumber(nums, i, j, visited);
    }
private:
    int longestOfNumber(std::vector<std::vector<int>> &nums, int i, int j, std::vector<std::vector<int>> &visited)
    {
        if (nums.size() == i + 1) {
            return nums[i][j];
        }
        
        if (visited[i][j] != INT_MIN) {
            return visited[i][j];
        }
        
        int a = longestOfNumber(nums, i + 1, j, visited);
        int b = longestOfNumber(nums, i + 1, j + 1, visited);
        int result = maxNum(a, b) + nums[i][j];
        visited[i][j] = result;
        
        return result;
        
    }
    inline int maxNum(int a, int b)
    {
        return a > b ? a : b;
    }
}; */

//动态规划法 Lintcode 32ms
class Solution {
public:
    int longestOfPath(std::vector<std::vector<int>> &nums)
    {
        for (int i = nums.size() - 2; i >= 0; --i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                int a = nums[i + 1][j] + nums[i][j];
                int b = nums[i + 1][j + 1] + nums[i][j];
                nums[i][j] = (a > b ? a : b);
            } 
        }
        
        return nums[0][0];
    }
};

int main(int argc, char *argv[])
{
    int count, tmp;
    std::vector<std::vector<int>> nums;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        std::vector<int> t;
        for (int j = 0; j <= i; ++j) {
            std::cin >> tmp;
            t.push_back(tmp);
        }
        nums.push_back(t);
    }
    Solution s;
//    std::cout << s.longestOfPath(nums, 0, 0) << std::endl;
    std::cout << s.longestOfPath(nums) << std::endl;
    
    return EXIT_SUCCESS;
}
