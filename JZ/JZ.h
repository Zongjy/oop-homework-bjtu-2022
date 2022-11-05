#ifndef CMATRIX_H__
#define CMATRIX_H__

#include <iostream>

using namespace std;

class CMatrix
{
private:
    int row;        // 矩阵行数
    int col;        // 矩阵列数
    double **mData; // 矩阵元素

public:
    CMatrix(int row = 0, int col = 0);        // 构造函数
    CMatrix(const CMatrix &);                 // 复制构造函数
    ~CMatrix();                               // 析构函数
    CMatrix operator+(const CMatrix &) const; // 矩阵乘法
    CMatrix operator-(const CMatrix &) const; // 矩阵减法
    CMatrix operator*(const CMatrix &) const; // 矩阵乘法
    CMatrix &operator=(const CMatrix &);      // 矩阵赋值
    double operator()(int, int) const;        // 获取矩阵某元素的值
    friend ostream &operator<<(ostream &, const CMatrix &); // 矩阵输出函数
    friend istream &operator>>(istream &, const CMatrix &); // 矩阵输入函数
};

#endif