/*************************************************************************
	> File Name: MergeSort.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月16日 星期三 08时09分42秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>
#include <unistd.h>

int divide(int num[], std::vector<int> &v, int n)
{

    v.push_back(0);

    for (int i = 0; i + 1 != n; ++i) {
        if (num[i] > num[i + 1]) {
            v.push_back(i + 1);
        }
    }

    v.push_back(n);

    return v.size();
}

void Merge(int num[], int low, int hig, int rear)
{
    int a[hig - low];
    int b[rear - hig];
    int k = low, i, j;

    for (i = low, j = 0; i < hig; ++i, ++j) {
        a[j] = num[i];
    }

    for (i = hig, j = 0; i < rear; ++i, ++j) {
        b[j] = num[i];
    }

    for (i = 0, j = 0; i <  hig - low && j < rear - hig;) {
        if (a[i] < b[j]) {
            num[k] = a[i];  ++i;
        } else if (a[i] > b[j]){
            num[k] = b[j]; ++j;
        } else {
            num[k] = a[i]; ++i, ++k;
            num[k] = b[j]; ++j;
        }
        ++k;
    }

    while (i < hig - low) {
        num[k] = a[i];
        ++i, ++k;
    }

    while (j < rear - hig) {
        num[k] = b[j];
        ++k, ++j;
    }
}

void MergeSort(int num[], int n)
{
    std::vector<int> v;
    int group;

    group = divide(num, v, n);
    
    //循环直到只剩一个组(两个下标)
    while (group != 2) {
        for (std::vector<int>::size_type i = 0; i < v.size() - 1; i += 2) {
            Merge(num, v[i], v[i + 1], v[i + 2]);
        }
        v.clear();
        group = divide(num, v, n);
    }

}

int main(int argc, char *argv[])
{
    int num[10];

    for (auto &a : num) {
        std::cin >> a;
    }

    MergeSort(num, 10);

    for (auto a : num) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}
