/*************************************************************************
	> File Name: 20.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月16日 星期六 15时26分21秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {
        const int size = s.size();
        std::vector<char> v;
        
        if (size % 2) {
            return false;
        } else if (size == 0) {
            return true;
        } else if (s[0] == ']' || s[0] == ')' || s[0] == '}') {
            return false;
        }
        
        for (int i = 0; i < size; ++i) {
            const char tmp = s[i];
            if (tmp == '(' || tmp == '{' || tmp == '[') {
                v.push_back(tmp);
            } else if (tmp == ')' || tmp == ']' || tmp == '}') {
                if (!v.size()) {
                    return false;
                }
                const char t = *(v.end() - 1);
                if ((tmp == ')' && t == '(') || (tmp == ']' && t == '[') || (tmp == '}' && t == '{')) {
                    v.pop_back();
                } else {
                    return false;
                }
            }else {
                return false;
            }
        }
        if (!v.size())
            return true;
        else {
            return false;
        }
    }
};

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
