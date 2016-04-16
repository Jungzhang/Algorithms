/*************************************************************************
	> File Name: 20.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年04月16日 星期六 15时26分21秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        const int size = s.size();
        std::stack<char> v;
        
        if (size % 2) {
            return false;
        } else if (size == 0) {
            return true;
        }
        
        for (int i = 0; i < size; ++i) {
            const char tmp = s[i];
            if (tmp == '(' || tmp == '{' || tmp == '[') {
                v.push(tmp);
            } else if ((!v.empty()) && ((tmp == ')' && v.top() == '(') || (tmp == ']' && v.top() == '[') || (tmp == '}' && v.top() == '{'))) {
                v.pop();
            } else {
                return false;
            }
        }
        if (v.empty())
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
