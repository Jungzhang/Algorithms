/*************************************************************************
	> File Name: 22.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月18日 星期一 21时40分19秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        
        if (n <= 0) {
            return result;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                
            }
        }
        
        return result;
    }
};

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
