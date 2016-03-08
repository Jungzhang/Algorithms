/*************************************************************************
	> File Name: Permutations.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月24日 星期四 20时27分45秒
	> Description:
 ************************************************************************/
#include <iostream>
#include <cstdlib>

int count;
int num[100];
int result[100];
bool visited[100] = {false};

void Permutations(int n)
{
    if (n == count) {
        for (int i = 0; i < n; ++i) {
            std::cout << result[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            result[n] = num[i];
            Permutations(n + 1);
            visited[i] = false;
        }
    }
}

int main(int argc, char *argv[])
{
    count  = 3;
    for (int i = 0; i < count; ++i) {
        num[i] = i + 1;
    }

    Permutations(0);
    
    return EXIT_SUCCESS;
}
