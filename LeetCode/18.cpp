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
        const int size = nums.size();
        int i = 0, j, k, m = size - 1;;
        
        if (size < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        
        while (i < m - 2) {
            j = i + 1;
            int sum1 = target - nums[i];
            while (j < m -1) {

                while (k < m) {
                    int sum2 = nums[j] + nums[k];
                    if (sum2 == target) {
                        result.push_back({nums[i], nums[j], nums[k]});
                    } else if (sum2 < target) {
                        
                    }
                }
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
