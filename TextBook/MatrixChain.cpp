/*************************************************************************
	> File Name: MatrixChain.cpp
	> Author: Jung
	> Mail: jungzhang@xiyoulinux.org  or  zhanggen.jung@gmail.com
	> Created Time: 2016年03月29日 星期二 15时29分25秒
	> Description: 矩阵连乘算法
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>

const int MAXSIZE = 100;

//两个矩阵的乘法
bool matrixMultiply(const int (&a)[MAXSIZE][MAXSIZE], const int (&b)[MAXSIZE][MAXSIZE], int (&c)[MAXSIZE][MAXSIZE],
    const int ca, const int ra, const int cb, const int rb)
{
    if (ca != rb) {
        std::cout << "矩阵不满足乘法条件" << std::endl;
        return false;   //错误处理
    }

    int sum = 0;
    
    //i控制a矩阵的行
    //j控制b矩阵的列
    //k控制a矩阵的列
    for (int i = 0; i < ra; ++i) {
        for (int j = 0; j < cb; ++j) {
            sum = 0;    //每次都应该把sum的值置为0
            for (int k = 0; k < ca; ++k) {  
                sum += a[i][k] * b[k][j];  //将a矩阵的行和b矩阵的每一列相乘
            }
            c[i][j] = sum;  //存入结果数组
        }
    }

    return true;
}

//计算矩阵连乘的最优计算次序和计算次数
void MatrixChain(const int (&p)[MAXSIZE], int n, int (&m)[MAXSIZE][MAXSIZE], int (&s)[MAXSIZE][MAXSIZE])
{
    for (int i = 1; i <= n; ++i) {
        m[i][i] = 0;    //当分割的矩阵是单一矩阵时其计算次数是0
    }

    //递推公式：m[i][j] = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
    //r代表当前矩阵相乘的个数
    for (int r = 2; r <= n; ++r) {
        //当有r个矩阵相乘时,所有的情况下的计算值,
        //如计算A[2:5],有A[2:2]+A[3:5]+P[1]*P[2]*p[5]
        //A[2:3]+A[4:5]+P[1]*P[3]*P[5]
        //A[2:4]+A[5:5]+P[1]*P[4]*P[5]
        
        for (int i = 1; i <= n - r + 1; ++i) {      //递推式的起始位置
            int j = i + r - 1;                  //递推式的终止位置
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];     //初始化为从第一个处分割,和剩余的相乘
            s[i][j] = i;    //将断开位置初始化为从第一个处断开
            for (int k = i + 1; k < j; ++k) {   //求每一个递推式的递推结果
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[i];     //计算递推式的结果
                if (t < m[i][j]) {      //如果新结果小于记录值则更新
                    m[i][j] = t;        //更新最小记录值
                    s[i][j] = k;        //更新断开位置
                }
            }
        }
    }
}

//输出最优计算次序
void Traceback(int i, int j, const int (&s)[MAXSIZE][MAXSIZE])
{
    if (i == j) {
        return ;
    }
    Traceback(i, s[i][j], s);
    Traceback(s[i][j] + 1, j, s);
    std::cout << "Multiply A" << i << "," << s[i][j];
    std::cout << "and A " << (s[i][j] + 1) << "," << j << std::endl;
}

/*int main(int argc, char *argv[])
{
    int a[MAXSIZE][MAXSIZE];
    int b[MAXSIZE][MAXSIZE];
    int c[MAXSIZE][MAXSIZE];
    int ca = 3, cb = 2, ra = 3, rb = 3;

    for (int i = 0; i < ra; ++i) {
        for (int j = 0; j < ca; ++j) {
            a[i][j] = j + 1;
        }
    }

    for (int i = 0; i < rb; ++i) {
        for (int j = 0; j < cb; ++j) {
            b[i][j] = j + 1;
        }
    }

    if (matrixMultiply(a, b, c, ca, ra, cb, rb)) {
        for (int i = 0; i < ra; ++i) {
            for (int j = 0; j < cb; ++j) {
                std::cout << c[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return EXIT_SUCCESS;
}*/

int main(int argc, char *argv[])
{
    int p[MAXSIZE] = {30, 35, 15, 5, 10, 20, 25};
    int n;
    int m[MAXSIZE][MAXSIZE] = {0,0}, s[MAXSIZE][MAXSIZE] = {0,0};

    n = 6;

    MatrixChain(p, n, m, s);
    Traceback(1, 6, s);
    std::cout << m[1][n] << std::endl;

    return EXIT_SUCCESS;
}
