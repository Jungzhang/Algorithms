/*************************************************************************
	> File Name: 16.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月12日 星期二 16时01分17秒
	> Description: 3Sums Closest
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <algorithm>

//暴力求解,运行时间116ms,打败1.98%的程序=、=
/*class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int result = target, dis = INT_MAX, dis_tmp, tmp;
        if (nums.size() == 0) {
            result = 0;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (k != j + 1 && nums[k] == nums[k - 1]) {
                        continue;
                    }
                    tmp = nums[i] + nums[j] + nums[k];
                    dis_tmp = abs(tmp - target);
                    if (dis_tmp < dis) {
                        dis = dis_tmp;
                        result = tmp;
                        if (result == target) {
                            return target;
                        }
                    }
                }
            }
        }
        
        return result;
    }
};*/

class Solution {
public: 
    int threeSumClosest(std::vector<int>& nums, int target) {
        
        const int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        //如果最大的三个数加起来还小于目标值,则最接近的就是这三个数相加
        if(nums[n-1] + nums[n-2] + nums[n-3] <= target)  {
            return nums[n-1] + nums[n-2] + nums[n-3];
        }
        
        //如果最小的三个数加起来还大于目标值,则最接近的就是这三个数相加
        if(nums[0] + nums[1] + nums[2] >= target) {
            return nums[0] + nums[1] + nums[2];
        }
        
        int tmp;  //候选数
        int dis = INT_MAX;  //距离
        
        //因为要选择三个数,所以i < n - 2
        for (int i = 0; i < n-2; i++) {
            //如果当前处理过的数字上一次处理过,则不再处理
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            //如果当前扫描的值加上最大的三个数字之后如果还小于目标值
            //说明和目标值相等的概率为零(即：差值为0的概率为0)
            if (nums[i] + nums[n-1] + nums[n-2] <= target) {
                tmp = nums[i] + nums[n-1] + nums[n-2];
                if (tmp == target) {
                    return target;
                }
                dis = tmp - target; //差值最小等于候选值减去目标值
                continue;
            }
            
            //如果和最大的三个数字相加之后大于目标值,说明还有希望找到差值为0的值
            //接下来就是求2Sums问题了(不同的一点是加了一个差值最小的判断)
            int target2 = target - nums[i];
            int j = i + 1; 
            int k = n - 1;
            
            while (j < k) {
                const int sum2 = nums[j] + nums[k];
                
                if (abs(sum2 - target2) < abs(dis)){
                    dis = sum2 - target2;
                }
                
                if(sum2 > target2) { 
                    k--;
                }
                
                else if(sum2 < target2) {
                    j++;
                }
                else {
                    return target;
                }
                while (nums[j] == nums[j-1]) {
                    j++;
                }
                while(nums[k] == nums[k+1]) {
                    k--;
                }
            }
        }
        return target + dis;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    
    return EXIT_SUCCESS;
}
