#include "CStudent.h"

int CStudent::mCount = 0;   // 定义全局变量 mCount 进行学生对象的计数

/// @brief 学生类默认构造函数
CStudent::CStudent()
{
    mpName = NULL;
    mCount++;
    // 利用sprintf函数进行学号的生成
    sprintf(mNo, "2128%04d", mCount);
}

/// @brief 学生类析构函数
CStudent::~CStudent()
{
    if (strlen(mpName) != 0)
        delete[] mpName;
    mCount--;
}

/// @brief 学生类复制构造函数
/// @param zS 
CStudent::CStudent(const CStudent &zS)
{
    strcpy(mNo, zS.mNo);
    // mpName = (char *)malloc(sizeof(zS.mpName));
    mpName = new char[strlen(zS.mpName)];
    strcpy(mpName, zS.mpName);
    for (int i = 0; i < 5; i++)
    {
        mScore[i] = zS.mScore[i];
    }
    mCount++;
}

/// @brief 学生类信息设置函数
void CStudent::SetStudent()
{
    cout << "请输入学生信息!" << endl;
    //      << "请输入学号(8位及以下):" << endl;
    // cin >> mNo;
    cout << "请输入姓名:" << endl;
    char tmp[1024];
    cin >> tmp;
    int len = strlen(tmp) + 1;  // 预留出末尾的'\0'
    // mpName = (char *)malloc(len * sizeof(char));
    mpName = new char[len];
    strcpy(mpName, tmp);
    cout << "请输入五科成绩(按空格隔开):" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> mScore[i];
    }
}

/// @brief 学生类信息显示函数
void CStudent::ShowStudent() const
{
    cout << "该学生信息如下:" << endl
         << "  学号: " << mNo << endl
         << "  姓名: " << mpName << endl;
    cout << "  各科成绩:";
    for (int i = 0; i < 5; i++)
    {
        cout << " " << mScore[i];
    }
    cout << endl;
}

/// @brief 学生类成绩比较函数(引用)
/// @param zS 
void CStudent::CompareScore(const CStudent &zS) const
{
    int diff = 0;
    for (int i = 0; i < 5; i++)
    {
        diff += mScore[i] - zS.mScore[i];
    }
    if (diff > 0)
    {
        cout << mpName << " 比 " << zS.mpName << " 学习成绩好!" << endl;
    }
    else if (diff == 0)
    {
        cout << mpName << " 与 " << zS.mpName << " 学习成绩不相上下!" << endl;
    }
    else
    {
        cout << mpName << " 比 " << zS.mpName << " 学习成绩差!" << endl;
    }
}

/// @brief 学生类成绩比较函数(指针)
/// @param zS 
void CStudent::CompareScore(const CStudent *zS) const
{
    int diff = 0;
    for (int i = 0; i < 5; i++)
    {
        diff += mScore[i] - zS->mScore[i];
    }
    if (diff > 0)
    {
        cout << mpName << " 比 " << zS->mpName << " 学习成绩好!" << endl;
    }
    else if (diff == 0)
    {
        cout << mpName << " 与 " << zS->mpName << " 学习成绩不相上下!" << endl;
    }
    else
    {
        cout << mpName << " 比 " << zS->mpName << " 学习成绩差!" << endl;
    }
}

/// @brief 学生类成绩比较函数(友元)
/// @param zS1 
/// @param zS2 
void CompareScore(const CStudent &zS1,const CStudent &zS2)
{
    int diff = 0;
    for (int i = 0; i < 5; i++)
    {
        diff += zS1.mScore[i] - zS2.mScore[i];
    }
    if (diff > 0)
    {
        cout << zS1.mpName << " 比 " << zS2.mpName << " 学习成绩好!" << endl;
    }
    else if (diff == 0)
    {
        cout << zS1.mpName << " 与 " << zS2.mpName << " 学习成绩不相上下!" << endl;
    }
    else
    {
        cout << zS1.mpName << " 比 " << zS2.mpName << " 学习成绩差!" << endl;
    }
}