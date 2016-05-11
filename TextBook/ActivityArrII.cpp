/*************************************************************************
	> File Name: ActivityArrII.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org
	> Created Time: 2016年05月11日 星期三 08时08分52秒
	> Description: 会场安排问题的O(n)复杂度解法,采用混排实现
                   求得同一时刻最大的不相容活动数即为需要的最少会场数
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

struct activity {
    unsigned int time;
    bool type; //true为开始,false为结束
};

class Solution {
public:
    unsigned int numOfHall(std::vector<activity> &acts) 
    {
        unsigned int count = 0, tmp = 0;

        if (acts.size() == 0) {
            return 0;
        }

        std::sort(acts.begin(), acts.end(), [](const activity &a, const activity &b){return a.time < b.time;});
        
        for (const auto &a : acts) {
            if (a.type == true) {
                ++tmp;
            } else {
                --tmp;
            }
            if (tmp > count) {
                count = tmp;
            }
        }
        
        return count;
    }
};

int main(int argc, char *argv[])
{
    std::vector<activity> acts;
    int count;

    std::cin >> count;
    for (int i = 0; i < count * 2; ++i) {
        unsigned int time;
        bool type;
        std::cin >> time >> type;
        acts.push_back({time, type});
    }

    Solution s;

    std::cout << s.numOfHall(acts) << std::endl;

    return EXIT_SUCCESS;
}
