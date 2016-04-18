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
    /*std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        
        if (n <= 0) {
            return result;
        }
        std::string s;
        addBrackets(n, n, s, result);
        
        return result;
    }*/
    std::vector<std::string> generateParenthesis(int n) {
        std::string s;
        std::vector<std::string> v;
        generate(n, n, s, v);
        return v;
    }
    void generate(int left, int right, std::string s, std::vector<std::string> &v){
        if(left){
            generate(left - 1, right, s + "(", v);
            if(left != right){
                generate(left, right - 1, s + ")", v);
            }
        }else{
            if(right){
                v.push_back(s + std::string(right,')'));
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
            std::string tmp = s + "(";
            addBrackets(left - 1, right, tmp, result);
        } else {
            if (left > 0) {
                std::string tmp = s + "(";
                addBrackets(left - 1, right, tmp, result);
            }
            if (right > 0) {
                std::string tmp = s + ")";
                addBrackets(left, right - 1, tmp, result);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
