/*************************************************************************
	> File Name: 1.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月26日 星期六 15时48分47秒
	> Description: LeetCode之1,给定一个数组和一个目标值,
    返回数组中两个数字加起来等于该目标值的下标
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

//暴力解法,超时

/*class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) {
                    continue;
                } else {
                    if (nums[i] + nums[j] == target) {
                        v.push_back(i);
                        v.push_back(j);
                        break;
                    }
                }
            }
            if (v.size() != 0) {
                break;
            }
        }
        return v;
    }

private:
    std::vector<int> v;
};
*/

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        
        /*for (int i = 0; i < nums.size(); ++i) {
            tmp[nums[i]] = i;
        }
        */
        for (int i = 0; i < nums.size(); ++i) {
            if (tmp.find(target - nums[i]) != tmp.end() && i != tmp[target - nums[i]]) {
                v.push_back(tmp[target- nums[i]]);
                v.push_back(i);
                break;
            } else {
                tmp[nums[i]] = i;
            }
        }
        
        return v;
    }

private:
    std::vector<int> v;
    std::map<int, int> tmp;
};

int main(int argc, char *argv[])
{
    std::vector<int> nums({3, 2, 4});
    int target = 6;

    Solution s;
    std::vector<int> v = s.twoSum(nums, target);

    for (auto a : v) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}
