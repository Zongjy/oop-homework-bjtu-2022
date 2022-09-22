#ifndef CParticle_H__
#define CParticle_H__

#include <iostream>
using namespace std;

#define rand_n(x) rand() % (x)
#define BOUNDARY 101 

class CParticle
{
private:
    int mX, mY; // 横纵坐标
    int mV;     // 质点移动速率

public:
    CParticle(int zV);                // 构造函数
    ~CParticle();                     // 析构函数
    void SetPosition(int zX, int zY); // 质点对象位置设置操作函数
    void SetVelocity(int zV);         // 质点对象速率设置操作函数
    void ShowPosition();              // 质点对象位置显示操作函数
    void MoveTrace();                 // 基于键盘控制的质点对象跟踪操作函数
    void MoveEastward();              // 质点对象右移操作函数
    void MoveWestward();              // 质点对象左移操作函数
    void MoveNorthward();             // 质点对象上移操作函数
    void MoveSouthward();             // 质点对象下移操作函数
};

#endif