#include "YZT.h"

int main()
{
    Circle c1;    // 创建圆类对象
    Cylinder cy1; // 创建圆柱体类对象
    cout << "请设置圆:" << endl;
    cin >> c1; // 输入设置c1
    cout << fixed << setprecision(2) << c1 << endl
         << "圆的面积为: " << c1.Area() << endl; // 输出c1的成员值并计算输出其面积
    cout << "请设置圆柱体:" << endl;
    cin >> cy1; // 输入设置cy1
    cout << cy1 << endl
         << "圆柱体的体积为: " << cy1.Volume() << endl; // 输出cy1的成员值并计算输出其体积
    return 0;
}