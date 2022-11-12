#include "YZT.h"

/// @brief 构造函数
/// @param r
Circle::Circle(double r /* = 0.0*/) : radius(r) {}

/// @brief 析构函数
Circle::~Circle() {}

/// @brief 面积计算函数(圆)
/// @return 圆面积
double Circle::Area() const
{
    return radius * radius * M_PI;
}

/// @brief 左移运算符重载(输出圆的半径)
/// @param os 输出流对象
/// @param zC 圆类对象
/// @return 输出流对象
ostream &operator<<(ostream &os, const Circle &zC)
{
    os << "半径: " << zC.radius;
    return os;
}

/// @brief 右移运算符重载(输入圆的半径)
/// @param is 输入流对象
/// @param zC 圆类对象
/// @return 输入流对象
istream &operator>>(istream &is, Circle &zC)
{
    cout << "请输入半径: ";
    is >> zC.radius;
    if (zC.radius < 0.0)
    {
        cout << "请输入大于零的半径长度!" << endl;
        zC.radius = 0.0;
    }
    return is;
}

/// @brief 构造函数
/// @param h 圆柱体高度
Cylinder::Cylinder(double h /* = 0.0*/) : height(h) {}

/// @brief 析构函数
Cylinder::~Cylinder() {}

/// @brief 体积计算函数
/// @return 圆柱体的体积
double Cylinder::Volume() const
{
    return this->Area() * this->height;
}

/// @brief 左移运算符重载(输出圆柱体的半径和高)
/// @param os 输出流对象
/// @param zCy 圆柱体对象
/// @return 输出流对象
ostream &operator<<(ostream &os, const Cylinder &zCy)
{
    os << (const Circle &)zCy << "  ";
    os << "高: " << zCy.height;
    return os;
}

/// @brief 右移运算符重载(输入圆柱体的半径和高)
/// @param is 输入流对象
/// @param zCy 圆柱体对象
/// @return 输入流对象
istream &operator>>(istream &is, Cylinder &zCy)
{
    is >> (Circle &)zCy;
    cout << "请输入高: ";
    is >> zCy.height;
    if (zCy.height < 0.0)
    {
        cout << "请输入大于零的高度!" << endl;
        zCy.height = 0.0;
    }
    return is;
}
