/*************************************************************************
	> File Name: 300.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月30日 星期三 09时04分46秒
	> Description:求数组中最长递增子序列的长度，
    如序列[10, 9, 2, 5, 3, 7, 101, 18]，则最长递增子序列是[2, 3, 7, 101]，
    所以程序返回4。要求O（nlogn）的时间复杂度。
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>

class Solution {
public:
    //二分法查找第一个大于tar的数字，返回其下标
    std::vector<int>::size_type BinarySearch(const std::vector<int> &nums, const int &tar)
    {
        int hig = nums.size() - 1;
        int low = 0;
        int mid;
        
        while (low <= hig) {
            mid = (hig + low) / 2;
            if (tar == nums[mid]) {
                return mid;
            } else if (tar < nums[mid]) {
                hig = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    //1、扫描原数组中的数，先判断是否大于结果数组中的最后一个（最大数），如果大于结果数组中的最大数则将这个数加入结果数组。否则，在结果数组中寻找第一个大于扫描数的数字下标，然后替换。
    //2、重复上述步骤直到把原数组遍历完。
    //3、查找的方法可以使用二分法查找，还需要将原数组遍历一遍。所以时间复杂度为O（nlogn）。
    //4、本思路只能求解出长度，不能解出序列。
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> result;
        std::vector<int>::size_type tmp, index;
        
        if (nums.size() == 0) {
            return 0;
        }
        
        result.push_back(nums[0]);
        
        for (int i = 1; i != nums.size(); ++i) {
            tmp = nums[i];
            if (tmp > result[result.size() - 1]) {
                result.push_back(tmp);
            } else {
                index = BinarySearch(result, tmp);
                result[index] = tmp;
            }
        }
        return result.size();
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    std::vector<int> nums = {10,9,2,5,3,7,101,18};
    std::cout << s.lengthOfLIS(nums) << std::endl;
    
    return EXIT_SUCCESS;
}
