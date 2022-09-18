#ifndef FS_H
#define FS_H

#include <iostream>
using namespace std;

class CComplex
{
private:
    double mR; //实部
    double mI; //虚部

public:
    CComplex(double zR = 0.0, double zI = 0.0);
    ~CComplex();
    void SetValue();                              //* 复数对象设置1
    void SetValue(double zR, double zI);          //* 复数对象设置2
    void ShowValue();                             //* 复数对象显示
    CComplex Add(const CComplex &zC) const;       //* 复数加法
    CComplex Substract(const CComplex &zC) const; //* 复数减法
    CComplex Multiply(const CComplex &zC) const;  //* 复数乘法
    CComplex Divide(const CComplex &zC) const;    //* 复数除法
    friend ostream &operator<<(ostream &os, const CComplex &c);
};

#endif