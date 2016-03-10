/*************************************************************************
	> File Name: 15.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月11日 星期一 17时18分27秒
	> Description: 找出给定数组中所有三个数相加等于零的数字组合
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

//超时
/*
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        
        //边界判断
        if (nums.size() == 0) {
            return result;
        }
        
        std::sort(nums.begin(), nums.end()); //排序
        
        if (nums[0] > 0) {
            return result;
        } else if (nums[nums.size() - 1] < 0) {
            return result;
        }
        
        for (int i = 0; i < nums.size(); ++i) {  //选择第一个数
            int j = i + 1;  //第二个数的起始
            int k = nums.size() - 1;  //大数字的起始
            while (j < k){ //循环控制
                int tmp = nums[i] + nums[j] + nums[k];
                if (tmp > 0) { //如果大于零,则--k
                    --k;
                } else if (tmp < 0) {  //如果小于0,则++j
                    ++j;
                } else { 
                    std::vector<int> t = {nums[i], nums[j], nums[k]}; //加入结果数组
                    result.push_back(t);
                    --k; ++j;
                }
            }
        }
        //利用STL进行去重操作
        std::sort(result.begin(), result.end());
        auto end = std::unique(result.begin(), result.end());
        result.erase(end, result.end());
        
        return result;
    }
}; */

class Solution {
public:
    std::vector<std::vector<int> > threeSum(std::vector<int> &num) 
	{
	    sort(num.begin(), num.end());
	    int i=0, j=0, k=num.size()-1;
	    int num1 = 0;
        std::vector<int> tmp(3);
        std::vector<std::vector<int> > result;
        
	    for (; i < k-1; ) {  //i < k - 1,因为i是第一个较小的数字,所以必须小于大数的下标,因为是3个数,所以是i < k - 1
	    	num1 = 0-num[i];
	    	tmp[0] = num[i];
	    	for (j = i+1, k=num.size()-1; j < k;  ) {
	    		if (num[j] + num[k] == num1) {
	    			tmp[1] = num[j]; ++j;
	    			tmp[2] = num[k]; --k;
	    			result.push_back(tmp);
	    			while (j<k && num[j] == num[j-1]) { //如果当前选择扫描的第二个数字和其他的前一个已经处理过的数字相同则直接跳过
	    				j++;
	    			}
	    			while (j<k && num[k] == num[k+1]) { //如果当前选择扫描的大数字和其他的前一个已经处理过的大数字相同则直接跳过
	    				k--;
	    			}
	    		}
	    		else if (num[j] + num[k] < num1) { //如果小于结果值说明小数字小了,把第二个选择的小数字向前后移动(即增大)
	    			j++;
	    		}
	    		else { //如果大于结果值说明前边选择的两个小数字小了,所以把选择的大数字向前移动(即减小)
	    			k--;
	    		}
	    	}
	    	i++; 
	    	while (i<k-1 && num[i] == num[i-1]) { //对i值判重,如果和之前扫描的重复,则跳过
	    		i++;
	    	}
	    }
        
	    return result;
	}
};

int main(int argc, char *argv[])
{
    Solution s;
    std::vector<int> v = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};

    std::vector<std::vector<int>> a = s.threeSum(v);
    for (auto &b : a) {
        for (auto &c : b) {
            std::cout << c << "  ";
        }
        std::cout << std::endl;
    }
    
    return EXIT_SUCCESS;
}
