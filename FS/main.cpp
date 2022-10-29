#include <iostream>
#include "fs.h"

int main()
{
    CComplex c1(2, 3);
    cout << "c1: " << c1;
    CComplex c2;
    // 设置c2的值
    c2.SetValue();
    cout << "c2: " << c2;
    cout << "c1+c2 = " << c1 + c2 << endl
         << "c1-c2 = " << c1 - c2 << endl
         << "c1*c2 = " << c1 * c2 << endl
         << "c1/c2 = " << c1 / c2 << endl
         << "|c2| = " << double(c2) << endl;
    return 0;
}