#include <iostream>
#include "fs.h"

int main()
{
    int q = 1;
    while (q)
    {
        CComplex c1(2, 3);
        cout << "c1: " << c1;
        // c1.ShowValue();
        CComplex c2;
        c2.SetValue();
        // c2.ShowValue();
        cout << "c2: " << c2;
        // const CComplex c2(3, -6);
        // const CComplex c3(7, 2);
        // const CComplex c4(5, 2);
        // const CComplex c5(2, 2);
        c1.Add(c2).ShowValue();
        cout << "continue?(1 for continue, 0 for exit)" << endl;
        cin >> q;
    }
    return 0;
}