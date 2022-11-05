#include "JZ.h"

int main()
{
    // 分别初始化并赋值两个矩阵
    int test_row, test_col;
    cout << "请设置矩阵A:" << endl
         << "行数: ";
    cin >> test_row;
    cout << "列数: ";
    cin >> test_col;
    CMatrix mA(test_row, test_col);
    cout << "请按顺序输入矩阵各元素的值:" << endl
         << "(按从左至右, 从上至下输入, 元素之间以空格隔开)" << endl;
    cin >> mA;
    cout << "请设置矩阵B:" << endl
         << "行数: ";
    cin >> test_row;
    cout << "列数: ";
    cin >> test_col;
    CMatrix mB(test_row, test_col);
    cout << "请按顺序输入矩阵各元素的值:" << endl
         << "(按从左至右, 从上至下输入, 元素之间以空格隔开)" << endl;
    cin >> mB;
    // 定义一个矩阵用于获取运算结果
    CMatrix res;
    cout << "请输入想要执行的操作:" << endl;
    // 定义一个整型变量获取询问的操作序号
    int q = 1;
    while (q != 5)
    {
        cout << "1. 矩阵加法  2. 矩阵减法  3. 矩阵乘法  4. 获取矩阵A[i][j]的值 5. 退出" << endl;
        cin >> q;
        // 矩阵相加
        if (q == 1)
        {
            cout << "A + B = " << endl;
            res = mA + mB;
            cout << res;
        }
        // 矩阵相减
        else if (q == 2)
        {
            cout << "A - B = " << endl;
            res = mA - mB;
            cout << res;
        }
        // 矩阵相乘
        else if (q == 3)
        {
            cout << "A * B = " << endl;
            res = mA * mB;
            cout << res;
        }
        // 获取矩阵A[i][j]的元素值
        else if (q == 4)
        {
            int ipos, jpos;
            cout << "请输入需要获取的元素下标:" << endl
                 << "行数: ";
            cin >> ipos;
            cout << "列数: ";
            cin >> jpos;
            cout << "A[" << ipos << "][" << jpos << "] = "<< mA(ipos, jpos) << endl;
        }
        // 其他错误询问打印错误信息并继续循环
        else if (q != 5)
        {
            cout << "请输入有效值!" << endl;    
            continue;
        }
    }
    return 0;
}