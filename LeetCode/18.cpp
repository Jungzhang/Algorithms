/*************************************************************************
	> File Name: 18.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月15日 星期五 15时53分39秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> tmp(4);
        const int size = nums.size();
        int i = 0, j, k, m = size - 1;;
        
        if (size == 0 || size < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        
        while(i < m - 2) {
            tmp[0] = nums[i];
            ++i;
            while(i < m -2 && nums[i] == nums[i - 1]) {
                ++i;
            }
        }
        
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};

    std::vector<std::vector<int>> result = s.fourSum(nums, 0);
    
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << "   ";
        }
        std::cout << std::endl;
    }
    
    return EXIT_SUCCESS;
}
