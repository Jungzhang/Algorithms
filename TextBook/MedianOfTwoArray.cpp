/*************************************************************************
	> File Name: MedianOfTwoArray.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月16日 星期三 20时31分55秒
	> Description: 将两个等长有序数组的中位数,要求时间复杂度为O(logn)
 ************************************************************************/
#include <iostream>
#include <cstdlib>

//大体思想是：比较两个数组的中位数
//1、如果相同则该值就是中位数
//2、如果num1 < num2则中位数位于num1的后半部分或num2的前半部分
//3、如果num1 > num2则中位数位于num1的前半部分或num2的后半部分
//4、一直执行2和3直到数组划分到长度为1的时候则两个数中较小的数就是中位数
//数学原理为：
//1、数组中位数的左右两侧同时加上或者减去相同个数的数字则中位数不变
//2、数组中有一半的元素不小于中位数，有一半的元素不大于中位数
int MedianOfTwoArray(int num1[], int num2[], int len)
{
    int mid;
    
    while (true) {
        
        //如果数组长度被更新的只剩下一个元素,则中位数就在这两个元素中
        //根据中位数的定义可以知道中位数为较小的那一个
        if (len == 1) {
            return num1[0] < num2[0] ? num1[0] : num2[0];
        }
        
        //计算中位数的下标,因为len表示的是长度,所以要将长度减去1变成最大下标再除以2
        mid = (len - 1) / 2;
        
        //采用移动指针对于数组的指向的方法来达到分割数组的目的
        if (num1[mid] == num2[mid]) {
            return num1[mid];
        } else if (num1[mid] < num2[mid]) {
            num1 = num1 + len - mid - 1;
        } else {
            num2 = num2 + len - mid -1;
        }
        
        //因为数组被分割了,所以要更新数组的长度
        //因为更新后的数组是原数组的一半且mid代表下标,因此len = mid + 1
        len = mid + 1;
    }
    
}

int main(int argc, char *argv[])
{
    int num1[5] = {1, 3, 8, 10, 17};
    int num2[5] = {7, 9, 12, 15, 23};

    std::cout << MedianOfTwoArray(num1, num2, 5) << std::endl;

    
    return EXIT_SUCCESS;
}
