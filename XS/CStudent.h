#ifndef CSTUDENT_H__
#define CSTUDENT_H__

#include<iostream>
#include<string.h>
using namespace std;

class CStudent
{
private:
    char mNo[9];        //学号
    char *mpName;       //姓名
    int mScore[5];      //五门功课成绩
    static int mCount;  //学生对象计数

public:
    CStudent();         //构造函数
    CStudent(const CStudent &zS);   //拷贝构造函数
    ~CStudent();        //析构函数
    void SetStudent();  //学生对象(学号姓名成绩)设置操作函数
    void ShowStudent() const;       //学生对象显示操作函数
    void CompareScore(const CStudent &zS) const;    //学生对象比较函数1
    void CompareScore(const CStudent *zS) const;    //学生对象比较函数2
    friend void CompareScore(const CStudent &zS1, const CStudent &zS2); //友元比较函数
};

#endif