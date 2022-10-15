#include "CTriangle.h"

int main()
{
    // 创建三个顶点(固定数据)
    CPoint p1(0, 0), p2(0, 4), p3(7, 0);
    // 以这三个顶点初始化一个三角形
    CTriangle sjx(p1, p2, p3);
    // 计算并输出初始三角形顶点坐标和面积
    double area = sjx.Area();
    cout << "三角形顶点坐标分别为: ";
    cout << "A(" << p1.GetX() << ", " << p1.GetY() << "), ";
    cout << "B(" << p2.GetX() << ", " << p2.GetY() << "), ";
    cout << "C(" << p3.GetX() << ", " << p3.GetY() << ")" << endl;
    cout << "三角形面积为: " << area << endl;
    // 重新设置各顶点
    cout << "请依次修改各点坐标(分别输入各点新的横纵坐标, 用空格隔开)" << endl;
    cout << "A点: ";
    int tmpx, tmpy;
    cin >> tmpx >> tmpy;
    p1.SetPoint(tmpx, tmpy);
    cout << "B点: ";
    cin >> tmpx >> tmpy;
    p2.SetPoint(tmpx, tmpy);
    cout << "C点: ";
    cin >> tmpx >> tmpy;
    p3.SetPoint(tmpx, tmpy);
    // 以重新设置好的顶点更新三角形对象数据
    sjx.SetTriangle(p1, p2, p3);
    // 计算新三角形面积
    area = sjx.Area();
    // 计算新三角形各边长
    double d1 = p1.Distance(p2), d2 = p2.Distance(p3), d3 = p3.Distance(p1);
    // 如果存在某一边长为0, 说明存在相同点
    if ((d1 == 0.0 || d2 == 0.0 || d3 == 0.0) && area == 0)
    {
        cout << "存在相同点, 无法构成三角形" << endl;
    }
    // 如果各边长均大于0, 而三角形面积为0, 说明三顶点共线
    else if(d1 > 0.0 && d2 > 0.0 && d3 > 0.0 && area == 0)
    {
        cout << "三顶点共线, 无法构成三角形" << endl;
    }
    // 三顶点构成正常三角形, 输出新三角形面积
    else
    {
        cout << "新三角形面积为: " << area << endl;
    }
    return 0;
}
