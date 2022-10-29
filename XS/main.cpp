#include "CStudent.h"
int main()
{
    CStudent stu1, stu2;
    cout << "请设置第1个学生的信息:" << endl;
    stu1.SetStudent();
    stu1.ShowStudent();
    cout << "请设置第2个学生的信息:" << endl;
    stu2.SetStudent();
    stu2.ShowStudent();
    cout << "下面将比较第1、2个学生的成绩:" << endl;
    cout << "利用对象引用实现:(成员函数)" << endl;
    stu1.CompareScore(stu2);
    cout << "利用对象指针实现:(成员函数)" << endl;
    stu1.CompareScore(&stu2);
    cout << "利用对象引用实现:(友元函数)" << endl;
    CompareScore(stu1, stu2);
    return 0;
}