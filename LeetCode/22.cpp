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

//大体思路就是要保证左半括号个数大于等于右半括号
class Solution {
public:
    /*std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        
        if (n <= 0) {
            return result;
        }
        std::string s;
        addBrackets(n, n, s, result);
        
        return result;
    }*/
    
    //思想也是保证左半括号个数大于等于右半括号个数
    std::vector<std::string> generateParenthesis(int n) {
        std::string s;
        std::vector<std::string> result;
        generate(n, n, s, result);
        return result;
    }

    void generate(int left, int right, std::string s, std::vector<std::string> &result){
        if(left){
            generate(left - 1, right, s + "(", result); //如果左半括号还没有用完直接加左半括号
            if(left != right){    //如果左右不相等
                generate(left, right - 1, s + ")", result);    //加右半括号
            }
        }else{
            if(right){   //如果还剩右括号没有加入则将剩余的所有右括号都加入
                result.push_back(s + std::string(right,')'));
            }
        }
        return;
    }
private:
    void addBrackets(int left, int right, std::string s, std::vector<std::string> &result)
    {
        if (left == 0 && right == 0) {
            result.push_back(s);
            return;
        }
        
        if (left == right) {
            addBrackets(left - 1, right, s + "(", result);
        } else {
            if (left > 0) {
                addBrackets(left - 1, right, s + "(", result);
            }
            if (right > 0) {
                addBrackets(left, right - 1, s + ")", result);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
