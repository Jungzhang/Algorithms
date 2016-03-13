/*************************************************************************
	> File Name: 338.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月25日 星期五 11时18分08秒
	> Description: 给定数字num, 计算i在 0 <= i <= num 之间的所有数字二进制
        表示形式中1的数量,以数组的形式返回结果(时间复杂度要求在O(n),空间复
        杂度要求在O(n))
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>

class Solution {

public:
    std::vector<int> countBits(int num) {
        int count, tmp;
        for (int i = 0; i <= num; ++i) {
            for (count = 0, tmp = i; tmp; ++count) {
                tmp = tmp & (tmp - 1);
            }
            v.push_back(count);
        }
        
        return v;
    }

private:
    std::vector<int> v;

};

int main(int argc, char *argv[])
{
    Solution s;
    int a;

    std::cin >> a;
    std::vector<int> v = s.countBits(a);

    for (auto a = v.begin(); a != v.end(); ++a) {
        std::cout << *a << " ";
    }
    std::cout << std::endl;

    
    return EXIT_SUCCESS;
}
