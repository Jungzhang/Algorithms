/*************************************************************************
	> File Name: 4.c
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月02日 星期六 18时04分16秒
	> Description: 二分法在两个数组中寻找第k小的元素,这样每次可以近似的舍
    去某个数组中一半的元素,所以时间复杂度可以达到O(log(n+m))
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//寻找第k小的元素
//最终二分的效果是要么将nums1数组长度分割完,要么将k分割变成1
int findKth(int *nums1, int nums1Size, int *nums2, int nums2Size, int k)
{
    //保证第一个数组的长度小于等于第二个数组,便于以后的查找工作
    if (nums1Size > nums2Size) {
        return findKth(nums2, nums2Size, nums1, nums1Size, k);
    }

    //如果长度较小的数组长度为0,则返回nums2中下标为k-1
    if (nums1Size == 0) {
        return nums2[k - 1];
    }

    //如果k长度为1,则返回两个数组中较小的一个
    if (k == 1) {
        return nums1[0] < nums2[0] ? nums1[0] : nums2[0];
    }
    
    //在两个数组中二分查找第k小的元素
    int a = (k / 2 < nums1Size ? k / 2 : nums1Size), b = k - a;
    
    if (nums1[a - 1] < nums2[b - 1]) {
        return findKth(nums1 + a, nums1Size - a, nums2, nums2Size, k - a); //舍去nums1中a以前的数
    } else if (nums1[a - 1] > nums2[b - 1]) {
        return findKth(nums1, nums1Size, nums2 + b, nums2Size - b, k - b); //舍去nums2中b以前的数
    } else {
        return nums1[a - 1];    //如果相等则直接返回
    }
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int sum = nums1Size + nums2Size;

    if (sum & 0x01) {
        return findKth(nums1, nums1Size, nums2, nums2Size, sum / 2 + 1);
    } else {
        return (findKth(nums1, nums1Size, nums2, nums2Size, sum / 2 + 1) + findKth(nums1, nums1Size, nums2, nums2Size, sum / 2)) / 2.0;
    }

}

int main(int argc, char *argv[])
{
    int nums1[] = {};
    int nums2[] = {1};

    printf("%lf\n", findMedianSortedArrays(nums1, 0, nums2, 1));
    
    return EXIT_SUCCESS;
}
