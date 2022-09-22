#include "CStudent.h"

int CStudent::mCount = 0;

CStudent::CStudent()
{
    mpName = NULL;
    mCount++;
    int tmp = 21280000 + mCount, pos = 7;
    while (tmp)
    {
        mNo[pos] = (char)(48 + tmp % 10);
        tmp /= 10;
        pos -= 1;
    }
    mNo[8] = '\0';
}

CStudent::~CStudent()
{
    if (strlen(mpName) == 0)
        free(mpName);
    mCount--;
}

CStudent::CStudent(const CStudent &zS)
{
    strcpy(mNo, zS.mNo);
    mpName = (char *)malloc(sizeof(zS.mpName));
    strcpy(mpName, zS.mpName);
    for (int i = 0; i < 5; i++)
    {
        mScore[i] = zS.mScore[i];
    }
    mCount++;
}

void CStudent::SetStudent()
{
    cout << "请输入学生信息!" << endl;
    //      << "请输入学号(8位及以下):" << endl;
    // cin >> mNo;
    cout << "请输入姓名:" << endl;
    char tmp[1024];
    cin >> tmp;
    int len = strlen(tmp) + 1;
    mpName = (char *)malloc(len * sizeof(char));
    strcpy(mpName, tmp);
    cout << "请输入五科成绩(按空格隔开)" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> mScore[i];
    }
}

void CStudent::ShowStudent() const
{
    cout << "该学生信息如下:" << endl
         << "学号: " << mNo << endl
         << "姓名: " << mpName << endl;
    cout << "各科成绩:";
    for (int i = 0; i < 5; i++)
    {
        cout << " " << mScore[i];
    }
    cout << endl;
}

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