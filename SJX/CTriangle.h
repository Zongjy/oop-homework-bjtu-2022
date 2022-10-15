#ifndef CTRIANGLE_H__
#define CTRIANGLE_H__

#include<iostream>
#include<cmath>

using namespace std;

class CPoint
{
private:
    int mX; //横坐标
    int mY; //纵坐标

public:
    CPoint(int zX, int zY);                 //构造函数
    ~CPoint();                              //析构函数
    void SetPoint(int zX, int zY);          //设置操作函数
    int GetX() const;                       //横坐标提取函数
    int GetY() const;                       //纵坐标提取函数
    double Distance(const CPoint &zP) const;//点间距离提取函数
};

class CTriangle
{
private:
    CPoint mVertex[3];  //三角形顶点

public:
    CTriangle(const CPoint &zP1, const CPoint &zP2, const CPoint &zP3);       //构造函数
    ~CTriangle();                           //析构函数
    void SetTriangle(const CPoint &zP1, const CPoint &zP2, const CPoint &zP3);//设置操作函数
    double Area() const;                    //面积计算函数
};

#endif