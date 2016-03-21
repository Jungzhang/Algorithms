/*************************************************************************
	> File Name: Mode.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月17日 星期四 22时02分58秒
	> Description: 众数问题,求众数和众数的个数
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <map>

void ModeOfMap(int num[], int n, int &mode, int &weight)
{
    std::map<int, int> m;
    mode = 0;
    weight = 0;

    for (int i = 0; i < n; ++i) {
        ++m[num[i]];
    }

    for (auto a = m.begin(); a != m.end(); ++a) {
        if ((*a).second > weight) {
            mode = (*a).first;
            weight = (*a).second;
        }
    }
}

int main(int argc, char *argv[])
{
    int n, mode, weight;
    
    std::cin >> n;
    
    int num[n];

    for (auto &a : num) {
        std::cin >> a;
    }

    ModeOfMap(num, n, mode, weight);

    std::cout << "众数：" << mode << std::endl << "重数：" << weight << std::endl;
    
    return EXIT_SUCCESS;
}
