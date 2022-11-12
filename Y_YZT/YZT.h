#ifndef YZT_H__
#define YZT_H__

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/// @brief 圆类
class Circle
{
private:
    double radius; //半径

public:
    Circle(double r = 0.0);
    virtual ~Circle();
    double Area() const;
    friend ostream &operator<<(ostream &, const Circle &);
    friend istream &operator>>(istream &, Circle &);
};

class Cylinder : public Circle // 由圆类公有派生
{
private:
    double height; // 高度

public:
    Cylinder(double h = 0.0);
    virtual ~Cylinder();
    double Volume() const;
    friend ostream &operator<<(ostream &, const Cylinder &);
    friend istream &operator>>(istream &, Cylinder &);
};

#endif