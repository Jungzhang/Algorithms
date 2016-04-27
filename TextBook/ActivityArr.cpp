/*************************************************************************
	> File Name: ActivityArr.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org
	> Created Time: 2016年04月27日 星期三 08时27分49秒
	> Description: 活动安排问题,给定n个活动的开始时间和结束时间,每个会场
    某一时刻只能安排一个活动,求最小会场数
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

struct activity {
    unsigned int start;
    unsigned int end;
    bool flag = true;
};

class Solution {
    int numOfHall(std::vector<activity> acts)
    {
        int count = 0;
        const int size = acts.size();
        
        if (size == 0) {
            return 0;
        }
        
        std::sort(acts.begin(), acts.end(), [](const activity &a, const activity &b) {return a.end < b.end;});
        
        int tmp = size;
        while (tmp) {
            int end = -1;
            for (int i = 0; i < size; ++i) {
                if (acts[i].flag && end == -1) {
                    end = acts[i].end;
                } else if (acts[i].flag && acts[i].end >= acts[end].end) {
                    end = i;
                } else {
                    continue;
                }
                acts[i].flag = false;
                --tmp;
            }
            ++count;
        }
        
        return count;
    }
};

int main(int argc, char *argv[])
{

    return EXIT_SUCCESS;
}
