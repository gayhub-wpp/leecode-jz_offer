#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
// 保证base和exponent不同时为0

// 暴力，幂为负数时a^(-b) = (1/a)^b
double Power1(double base, int exponent) {
    double result = 1;
    if(exponent<0){
        base = 1/base;
        exponent = -exponent;
    }
    for(int i = 1; i<= exponent; ++i){
        result *= base;
    }
    return result;
}

// 递归，b^n = (b ^ (n/2)) ^ 2
// n为奇数再乘一个base
double q_power(double base, int exponent){
    if (exponent == 0)  return 1.0;
    double ret = q_power(base, exponent/2);
    if (exponent & 1)   return ret*ret*base;
    else   return  ret*ret;
}
double Power2(double base, int exponent) {
    if(exponent<0){
        base = 1/base;
        exponent = -exponent;
    }
    return q_power(base, exponent);
}

// 非递归快速幂，将幂转化为2进制运算方式，带到base上，即二进制为1的位数相乘
// 6   = 1*2^2  + 1*2^1 + 0*2^0
// b^6 = b^(2^2 +  2^1  + 0) = b^(2^2) * b^(2^1) * b^0
double Power3(double base, int exponent) {
    if(exponent<0){
        base = 1/base;
        exponent = -exponent;
    }
    double ret = 1.0;
    double tmp = base;
    while(exponent){     //每次处理二进制的最后一位
        if(exponent &1) ret *= base;   //当前位为1，乘上当前base
        base *= base;    //每进一位，base^2,与二进制规则一致
        exponent >>= 1;   //进一位
    }
    return ret;
}

// template <class T,class Integer, class MonoidOperation>
// T power_this(T x, Integer n, MonoidOperation op){ // 可以看成求pow(x, n)
//     if (n == 0)
//         return identity_element(op); // 可以看成 1
//     else{
//         while ((n & 1) == 0){
//             n >>= 1;
//             x = op(x, x); //op看成乘法
//         }
//         T result = x; // 遇到 二进制中从低位到高位的第一个 1
//         n >>= 1;
//         while (n != 0){
//             x = op(x, x);
//             if ((n & 1) != 0)
//                 result = op(result, x);
//             n >>= 1;
//         }
//         return result;
//     }
// }

int main(int argc, char const *argv[])
{
    cout << Power1(2,4) << endl;
    cout << Power2(2,4) << endl;
    cout << Power3(2,4) << endl;
    cout << pow(2,4) <<endl;
    return 0;
}
