#include "JZ.h"

/// @brief 矩阵类的构造函数
/// @param zrow 矩阵行数(缺省为0)
/// @param zcol 矩阵列数(缺省为0)
CMatrix::CMatrix(int zrow /*=0*/, int zcol /*=0*/)
{
    row = zrow;
    col = zcol;
    mData = new double *[row];
    if (mData == nullptr)
        exit(-1);
    for (int i = 0; i < row; i++)
    {
        mData[i] = new double[col];
        if (mData[i] == nullptr)
            exit(-1);
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mData[i][j] = 0.0;
        }
    }
}

/// @brief 矩阵类的复制构造函数(深拷贝)
/// @param zM 被复制的矩阵
CMatrix::CMatrix(const CMatrix &zM)
{
    row = zM.row;
    col = zM.col;
    mData = new double *[zM.row];
    if (mData == nullptr)
        exit(-1);
    for (int i = 0; i < row; i++)
    {
        mData[i] = new double[col];
        if (mData[i] == nullptr)
            exit(-1);
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mData[i][j] = zM.mData[i][j];
        }
    }
}

/// @brief 矩阵类析构函数(释放为mData成员申请的内存空间)
CMatrix::~CMatrix()
{
    for (int i = 0; i < row; i++)
    {
        delete[] mData[i];
        mData[i] = nullptr;
    }
    delete[] mData;
    mData = nullptr;
}

/// @brief 矩阵类输入函数(重载右移运算符)
/// @param is (输入流对象)
/// @param zM (矩阵类对象)
/// @return 输入流对象
istream& operator>>(istream& is,CMatrix &zM)
{
    for (int i = 0; i < zM.row; i++)
    {
        for (int j = 0; j < zM.col; j++)
        {
            is >> zM.mData[i][j];
        }
    }
    return is;
}

/// @brief 矩阵类输出函数(重载左移运算符)
/// @param os (输出流对象)
/// @param zM (矩阵类对象)
/// @return 输出流对象
ostream& operator<<(ostream& os,const CMatrix&zM)
{
    // 按行向量的格式输出矩阵
    for (int i = 0; i < zM.row; i++)
    {
        if (i == 0)
            os << "[[";
        else
            os << " [";
        for (int j = 0; j < zM.col - 1; j++)
        {
            os << zM.mData[i][j] << ", ";
        }
        os << zM.mData[i][zM.col - 1];
        if (i == zM.row - 1)
            os << "]]";
        else
            os << "],";
        os << endl;
    }
    return os;
}

/// @brief 实现矩阵类的加法
/// @param zM (矩阵)
/// @return 和(矩阵)
CMatrix CMatrix::operator+(const CMatrix &zM) const
{
    // 当矩阵类型大小不匹配时, 返回零矩阵并输出错误信息
    if (row != zM.row || col != zM.col)
    {
        cout << "矩阵无法相加" << endl;
        return CMatrix(row, col);
    }
    CMatrix temp(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp.mData[i][j] = mData[i][j] + zM.mData[i][j];
        }
    }
    return temp;
}

/// @brief 实现矩阵类的减法
/// @param zM (矩阵)
/// @return 差(矩阵)
CMatrix CMatrix::operator-(const CMatrix &zM) const
{
    // 当矩阵类型大小不匹配时, 返回零矩阵并输出错误信息
    if (row != zM.row || col != zM.col)
    {
        cout << "矩阵无法相减" << endl;
        return CMatrix(row, col);
    }
    CMatrix temp(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp.mData[i][j] = mData[i][j] - zM.mData[i][j];
        }
    }
    return temp;
}

/// @brief 实现矩阵类的乘法
/// @param zM (矩阵)
/// @return 积(矩阵)
CMatrix CMatrix::operator*(const CMatrix &zM) const
{
    // 如果乘号前矩阵列数不等于乘号后矩阵行数, 无法实现矩阵相乘, 返回零矩阵并输出错误信息
    if (col != zM.row)
    {
        cout << "矩阵无法相乘" << endl;
        return CMatrix(row, zM.col);
    }
    CMatrix temp(row, zM.col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < zM.col; j++)
        {
            temp.mData[i][j] = 0;
            for (int k = 0; k < col; k++)
            {
                temp.mData[i][j] += mData[i][k] * zM.mData[k][j];
            }
        }
    }
    return temp;
}

/// @brief 实现矩阵类的赋值运算
/// @param zM 用于赋值的源矩阵
/// @return 被赋值的矩阵(*this)
CMatrix &CMatrix::operator=(const CMatrix &zM)
{
    // 避免自赋值
    if (this == &zM)
    {
        return *this;
    }
    // 当矩阵类型大小不匹配时, 释放mData内存空间并重新申请合适的大小
    if (row != zM.row || col != zM.col)
    {
        row = zM.row;
        col = zM.col;
        for (int i = 0; i < row; i++)
        {
            delete[] mData[i];
            mData[i] = nullptr;
        }
        delete[] mData;
        mData = nullptr;
        mData = new double *[row];
        if (mData == nullptr)
            exit(-1);
        for (int i = 0; i < row; i++)
        {
            mData[i] = new double[col];
            if (mData[i] == nullptr)
                exit(-1);
        }
    }
    // 对mData每一位的元素进行赋值
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mData[i][j] = zM.mData[i][j];
        }
    }
    return *(this);
}

/// @brief 查询矩阵某位置的值
/// @param zrow 行下标(从0开始)
/// @param zcol 列下标(从0开始)
/// @return 该下标对应的矩阵元素值
double CMatrix::operator()(int zrow, int zcol) const
{
    // 访问位置不存在的情况返回0.0, 并输出错误信息
    if (zrow < 0 || zrow >= row || zcol < 0 || zcol >= col)
    {
        cout << "访问位置不存在" << endl;
        return 0.0;
    }
    return mData[zrow][zcol];
}