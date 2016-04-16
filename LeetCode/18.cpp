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

//先选定两个数字,确定和
//然后再选定两个数字,确定和
//如果确定的两个中间值相等则成功
//否则按照3Sum处理重复选择的方法一样
class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        const int size = nums.size();
        int i = 0, j, k, m;
        
        if (size < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        
        while (i < m - 2) {
            j = i + 1;
            int sum1 = target - nums[i];   //选定一个之后还剩的大小
            
            while (j < m -1) {
                int sum2 = sum1 - nums[j];    //选定两个之后还剩的大小
                k = j + 1;
                m = size - 1;
                //如果j的下两个数字相加都大于所要求的值说明以后的测试都会大于要求的值
                //所以本次循环已经没有什么意义了,应该改变i的值才有可能再次获得期望值
                if (nums[j + 1] + nums[j + 2] > sum2) {
                    break;
                }
                //如果最大的两个数字相加都小于要求值则说明j已经取小了,所以应该移动j之后再继续循环
                if (nums[size - 1] + nums[size - 2] < sum2) {
                    ++j;
                    continue;
                }
                while (k < m) {
                    int sum3 = nums[k] + nums[m];   //后两个之和
                    if (sum2 == sum3) {     //如果前两个之和和后两个之和相加之后和target相等
                        ++k;     
                        --m;
                        result.push_back({nums[i], nums[j], nums[k], nums[m]});
                        //如果上一次扫描的结果和本次扫描的结果相同则直接跳过
                        while (k < m && nums[m] == nums[m + 1]) {
                            --m;
                        }
                        while (k < m && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                    } else if (sum3 < sum2) {
                        ++k;
                    } else {
                        --m;
                    }
                }
                ++j;
                while(j < m - 1 && nums[j] == nums[j - 1]) {
                    ++j;
                }
            }
            ++i;
            while(i < m - 2 && nums[i] == nums[i - 1]) {
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
