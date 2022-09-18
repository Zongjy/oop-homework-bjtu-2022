#include"CParticle.h"

CParticle::CParticle(int zV = 1)
{
    mX = rand_n(BOUNDARY);
    mY = rand_n(BOUNDARY);
    mV = zV;
    cout << "<=[" << mX << ", " << mY << "]\n";
}

CParticle::~CParticle()
{
    cout << "[" << mX << ", " << mY << "]=>\n";
}

void CParticle::SetPosition(int zX, int zY)
{
    mX = zX;
    mY = zY;
}

void CParticle::SetVelocity(int zV)           // 质点对象速率设置操作函数
{
    mV = zV;
}

void CParticle::ShowPosition()                // 质点对象位置显示操作函数
{
    cout << "当前质点坐标: [" << mX << "," << mY << "]\n";
}

void CParticle::MoveTrace()                   // 基于键盘控制的质点对象跟踪操作函数
{
    cout << "请输入字符控制质点移动:\nq: 结束移动  h: 向左移动  j: 向下移动  k: 向上移动  l: 向右移动\n";
    char op;
    cin >> op;
    while(op!='q')
    {
        if(op=='h')
            this->MoveWestward();
        else if (op=='j')
            this->MoveSouthward();
        else if(op=='k')
            this->MoveNorthward();
        else if(op=='l')
            this->MoveEastward();
        else
            cout << "输入非法, 请重新输入:\n";
        cin >> op;
    }
    cout << "移动结束!\n";
    this->ShowPosition();
}

void CParticle::MoveEastward()                // 质点对象右移操作函数
{
    mX += mV;
    this->ShowPosition();
    cout << "请输入下一操作字符:\n";
}

void CParticle::MoveWestward()                // 质点对象左移操作函数
{
    mX -= mV;
    this->ShowPosition();
    cout << "请输入下一操作字符:\n";
}

void CParticle::MoveNorthward()               // 质点对象上移操作函数
{
    mY += mV;
    this->ShowPosition();
    cout << "请输入下一操作字符:\n";
}

void CParticle::MoveSouthward()               // 质点对象下移操作函数
{
    mY -= mV;
    this->ShowPosition();
    cout << "请输入下一操作字符:\n";
}