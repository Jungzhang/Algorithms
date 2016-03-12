/*************************************************************************
	> File Name: 4.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月31日 星期四 20时58分26秒
	> Description: 两个已经排序的数组(长度可能不同),求两个数组合并后的中位
    数,要求时间复杂度是O(log(m+n))
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>


//查找次数：(m+n)/2
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int>::size_type sum = nums1.size() + nums2.size(), j = 0, k = 0;
        double result;
        
        if (nums1.size() == 0 && nums2.size() != 0) {
            if (sum % 2 == 0) {
                return (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2.0;
            } else {
                return nums2[nums2.size() / 2];
            }
        } else if (nums2.size() == 0 && nums1.size() != 0) {
            if (sum % 2 == 0) {
                return (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2.0;
            } else {
                return nums1[nums1.size() / 2];
            }
        }
        
        if (sum % 2 == 0 ) {
            for (int i = 0; i <=  (sum / 2); ++i) {
                if ((j != nums1.size() && nums1[j] < nums2[k]) || k == nums2.size()) {
                    if (i == sum / 2) {
                        result += nums1[j]; ++j;
                    } else {
                        result = nums1[j]; ++j;
                    }
                } else {
                    if (i == sum / 2) {
                        result += nums2[k]; ++k;
                    } else {
                        result = nums2[k]; ++k;
                    }
                }
            }
            result /= 2.0;
        } else {
            for (int i = 0; i <= (sum / 2); ++i) {
                if ((j != nums1.size() && nums1[j] < nums2[k]) || k == nums2.size()) {
                    result = nums1[j]; ++j;
                } else {
                    result = nums2[k]; ++k;
                }
            }
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    std::vector<int> a = {1};
    std::vector<int> b = {2, 3};

    std::cout << s.findMedianSortedArrays(a, b) << std::endl;
    
    return EXIT_SUCCESS;
}
