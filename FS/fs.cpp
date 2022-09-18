#include"fs.h"

CComplex::CComplex(double zR, double zI)
{
    mR = zR;
    mI = zI;
}

CComplex::~CComplex(){}

void CComplex::SetValue()
{
    cout << "请设置复数的实部：" << endl;
    cin >> mR;
    cout << "请设置复数的虚部：" << endl;
    cin >> mI;
}

void CComplex::SetValue(double zR, double zI)
{
    mR = zR;
    mI = zI;
}

void CComplex::ShowValue()
{
    cout.precision(3);
    if (mR == 0.0 && mI == 0.0)
    {
        cout << "0" << endl;
    }
    else if (mR == 0.0 && mI != 0.0)
    {
        if(mI==1)
            cout << "i" << endl;
        else if (mI==-1)
            cout << "-i" << endl;
        else
            cout << mI << "i" << endl;
    }
    else if (mR != 0.0 && mI == 0.0)
    {
        cout << mR << endl;
    }
    else
    {
        cout << mR;
        cout.setf(ios_base::showpos);
        if(mI==1)
            cout << "+i" << endl;
        else if (mI==-1)
            cout << "-i" << endl;
        else
            cout << mI << "i" << endl;
        cout.unsetf(ios_base::showpos);
    }
}

CComplex CComplex::Add(const CComplex &zC) const
{
    return CComplex(mR + zC.mR, mI + zC.mI);
}

CComplex CComplex::Substract(const CComplex &zC) const
{
    return CComplex(mR - zC.mR, mI - zC.mI);
}

CComplex CComplex::Multiply(const CComplex &zC) const
{
    return CComplex(mR * zC.mR - mI * zC.mI, mR * zC.mI - mI * zC.mR);
}

CComplex CComplex::Divide(const CComplex &zC) const
{
    double tmp = zC.mR * zC.mR + zC.mI * zC.mI;
    return CComplex((mR * zC.mR + mI * zC.mI) / tmp, (mI * zC.mR - mR * zC.mI) / tmp);
}

ostream & operator<<(ostream & os,const CComplex & c)
{
    os.precision(3);
    if (c.mR == 0.0 && c.mI == 0.0)
    {
        os << "0" << endl;
    }
    else if (c.mR == 0.0 && c.mI != 0.0)
    {
        if(c.mI==1)
            os << "i" << endl;
        else if (c.mI==-1)
            os << "-i" << endl;
        else
            os << c.mI << "i" << endl;
    }
    else if (c.mR != 0.0 && c.mI == 0.0)
    {
        os << c.mR << endl;
    }
    else
    {
        os << c.mR;
        os.setf(ios_base::showpos);
        if(c.mI==1)
            os << "+i" << endl;
        else if (c.mI==-1)
            os << "-i" << endl;
        else
            os << c.mI << "i" << endl;
        os.unsetf(ios_base::showpos);
    }
    return os;
}