#include "CTriangle.h"

CPoint::CPoint(int zX = 0, int zY = 0)
{
    // 点类默认构造函数
    mX = zX;
    mY = zY;
}

CPoint::~CPoint()
{
    // 析构点
}

void CPoint::SetPoint(int zX, int zY)
{
    // 将私有变量横纵坐标分别赋值
    mX = zX;
    mY = zY;
}

int CPoint::GetX() const
{
    // 返回横坐标值
    return mX;
}

int CPoint::GetY() const
{
    // 返回纵坐标值
    return mY;
}

double CPoint::Distance(const CPoint &zP) const
{
    // 计算两点之间的欧氏距离
    return sqrt(pow(zP.mX - mX, 2.0) + pow(zP.mY - mY, 2.0));
}

CTriangle::CTriangle(const CPoint &zP1 = CPoint(0, 0), const CPoint &zP2 = CPoint(0, 1),
                     const CPoint &zP3 = CPoint(1, 0))
{
    // 三角形类默认构造函数
    mVertex[0] = zP1;
    mVertex[1] = zP2;
    mVertex[2] = zP3;
}

CTriangle::~CTriangle()
{
    // 三角形类析构函数
}

void CTriangle::SetTriangle(const CPoint &zP1, const CPoint &zP2, const CPoint &zP3)
{
    // 三角形类重新设置各顶点坐标
    mVertex[0] = zP1;
    mVertex[1] = zP2;
    mVertex[2] = zP3;
}

double CTriangle::Area() const
{
    // 利用叉乘计算三角形面积, 注意要取绝对值
    int x1 = mVertex[0].GetX(), x2 = mVertex[1].GetX(), x3 = mVertex[2].GetX();
    int y1 = mVertex[0].GetY(), y2 = mVertex[1].GetY(), y3 = mVertex[2].GetY();
    return fabs((x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1)) / 2.0;
}