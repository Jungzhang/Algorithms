/*************************************************************************
	> File Name: 10.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月06日 星期三 20时01分50秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int pos = 0;
        bool flag = false;
        
        if (p.size() != 0 && s.size() == 0) {
            return false;
        } else if (p.size() == 0 && s.size() != 0) {
            return false;
        }
        
        if (p.size() != 0 && p == ".*") {
            return true;
        }
        
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == '.') {
                ++pos;
            }else if (i + 1 < p.size() && p[i+1] == '*') {
                while(pos != s.size() && s[pos] == p[i]) 
                    ++pos;
                if (i == p.size()) {
                    return true;
                }
                ++i;
            } else if (pos < s.size() && p[i] == s[pos]) {
                ++pos;
            } else {
                return false;
            }
        }
        if (pos != s.size()) {
            return false;
        }
        
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    std::cout << s.isMatch("aaa", "a*a") << std::endl;
    
    return EXIT_SUCCESS;
}
