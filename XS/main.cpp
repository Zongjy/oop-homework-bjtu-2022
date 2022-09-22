#include "CStudent.h"

int main()
{
    {
        // CStudent stu1;
        // stu1.SetStudent();
        // stu1.ShowStudent();
        // cout << "拷贝构造:" << endl;
        // CStudent stu2(stu1);
        // stu2.SetStudent();
        // stu2.ShowStudent();
        // stu1.CompareScore(stu2);
        // stu2.CompareScore(&stu2);
        CStudent stu[7];
        for (int i = 0; i < 7;i++)
        {
            stu[i].SetStudent();
            stu[i].ShowStudent();
        }
    }
    return 0;
}