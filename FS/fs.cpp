#include "fs.h"

CComplex::CComplex(double zR, double zI)
{
    mR = zR;
    mI = zI;
}

CComplex::~CComplex() {}

void CComplex::SetValue()
{
    cout << "请设置复数的实部：" << endl;
    cin >> mR;
    cout << "请设置复数的虚部：" << endl;
    cin >> mI;
}

void CComplex::SetValue(double zR, double zI)
{
    mR = zR;
    mI = zI;
}

void CComplex::ShowValue()
{
    cout.precision(3);
    if (mR == 0.0 && mI == 0.0)
    {
        cout << "0" << endl;
    }
    else if (mR == 0.0 && mI != 0.0)
    {
        if (mI == 1)
            cout << "i" << endl;
        else if (mI == -1)
            cout << "-i" << endl;
        else
            cout << mI << "i" << endl;
    }
    else if (mR != 0.0 && mI == 0.0)
    {
        cout << mR << endl;
    }
    else
    {
        cout << mR;
        cout.setf(ios_base::showpos);
        if (mI == 1)
            cout << "+i" << endl;
        else if (mI == -1)
            cout << "-i" << endl;
        else
            cout << mI << "i" << endl;
        cout.unsetf(ios_base::showpos);
    }
}

// CComplex CComplex::Add(const CComplex &zC) const
// {
//     return CComplex(mR + zC.mR, mI + zC.mI);
// }

// CComplex CComplex::Substract(const CComplex &zC) const
// {
//     return CComplex(mR - zC.mR, mI - zC.mI);
// }

// CComplex CComplex::Multiply(const CComplex &zC) const
// {
//     return CComplex(mR * zC.mR - mI * zC.mI, mR * zC.mI - mI * zC.mR);
// }

// CComplex CComplex::Divide(const CComplex &zC) const
// {
//     double tmp = zC.mR * zC.mR + zC.mI * zC.mI;
//     return CComplex((mR * zC.mR + mI * zC.mI) / tmp, (mI * zC.mR - mR * zC.mI) / tmp);
// }

/// @brief 求复数的模长
CComplex::operator double() const
{
    return sqrt(mR * mR + mI * mI);
}

/// @brief 重载加法运算符(成员运算符), 实现两个复数的加法
/// @param zC 被加数
/// @return 和
CComplex CComplex::operator+(const CComplex &zC) const
{
    return CComplex(mR + zC.mR, mI + zC.mI);
}

/// @brief 重载减法运算符(成员运算符), 实现两个复数的减法
/// @param zC 
/// @return 差
CComplex CComplex::operator-(const CComplex &zC) const
{
    return CComplex(mR - zC.mR, mI - zC.mI);
}

/// @brief 重载乘法运算符(友元运算符), 实现两个复数的乘法
/// @param zC1 
/// @param zC2 
/// @return 积
CComplex operator*(const CComplex &zC1, const CComplex &zC2)
{
    return CComplex(zC1.mR * zC2.mR - zC1.mI * zC2.mI, zC1.mR * zC2.mI + zC1.mI * zC2.mR);
}

/// @brief 重载除法运算符(友元运算符), 实现两个复数的除法
/// @param zC1 
/// @param zC2 
/// @return 商
CComplex operator/(const CComplex &zC1, const CComplex &zC2)
{
    double tmp = zC2.mR * zC2.mR + zC2.mI * zC2.mI;
    // 判断除数为0的情况, 也可以通过调用求模长来进行判断
    if(tmp == 0.0)
    {
        cout << "除数不能为0!" << endl;
        return CComplex(0, 0);
    }
    return CComplex((zC1.mR * zC2.mR + zC1.mI * zC2.mI) / tmp, (zC1.mI * zC2.mR - zC1.mR * zC2.mI) / tmp);
}

/// @brief 重载左移运算符, 实现直接利用ostream对象以"a+bi"的方式输出复数
/// @param os 
/// @param c 
/// @return ostream对象
ostream &operator<<(ostream &os, const CComplex &c)
{
    os.precision(3);
    if (c.mR == 0.0 && c.mI == 0.0)
    {
        os << "0" << endl;
    }
    else if (c.mR == 0.0 && c.mI != 0.0)
    {
        if (c.mI == 1)
            os << "i" << endl;
        else if (c.mI == -1)
            os << "-i" << endl;
        else
            os << c.mI << "i" << endl;
    }
    else if (c.mR != 0.0 && c.mI == 0.0)
    {
        os << c.mR << endl;
    }
    else
    {
        os << c.mR;
        os.setf(ios_base::showpos);
        if (c.mI == 1)
            os << "+i" << endl;
        else if (c.mI == -1)
            os << "-i" << endl;
        else
            os << c.mI << "i" << endl;
        os.unsetf(ios_base::showpos);
    }
    return os;
}