#include "Racional.h"

#include <iostream>

using namespace std;

Racional::Racional(int a, int b)
{
    num = a;
    if(b!=0&&a!=0)
    {
        den = b;
        simplificar();
        arreglarSigno();
    }
    else
    {
        if(b==0)
            cout << "El denominador no puede ser 0. Se reemplazara por un 1." << endl;
        den = 1;
    }
}

Racional::~Racional()
{
    //dtor
}

void Racional::simplificar()
{
    if( ((num%7)!=0) || ((den%7)!=0) )
        if( ((num%5)!=0) || ((den%5)!=0) )
            if( ((num%3)!=0) || ((den%3)!=0) )
                if( ((num%2)!=0) || ((den%2)!=0) )
                    return;
                else
                {
                    num = num/2;
                    den = den/2;
                }
            else
            {
                num = num/3;
                den = den/3;
            }
        else
        {
            num = num/5;
            den = den/5;
        }
    else
    {
        num = num/7;
        den = den/7;
    }
    simplificar();
}

void Racional::arreglarSigno()
{
    if(den>0)
        return;
    den = -den;
    num = -num;
}

Racional& Racional::operator=(const Racional& obj)
{
    num = obj.num;
    den = obj.den;
    return *this;
}

Racional Racional::operator+(const Racional& obj) const
{
    return (den==obj.den)?Racional(num+obj.num, den):Racional(num*obj.den+obj.num*den, den*obj.den);
}

Racional Racional::operator+(const int& n) const
{
    return Racional(num+n*den, den);
}

Racional operator+(const int& n, const Racional& obj)
{
    return Racional(obj.num+n*obj.den, obj.den);
}

Racional Racional::operator-(const Racional& obj) const
{
    return (den==obj.den)?Racional(num-obj.num, den):Racional(num*obj.den-obj.num*den, den*obj.den);
}

Racional Racional::operator-(const int& n) const
{
    return Racional(num-n*den, den);
}

Racional operator-(const int& n, const Racional& obj)
{
    return Racional(n*obj.den-obj.num, obj.den);
}

Racional Racional::operator*(const Racional& obj) const
{
    return Racional(num*obj.num,den*obj.den);
}

Racional Racional::operator*(const int& n) const
{
    return Racional(num*n, den);
}

Racional operator*(const int& n, const Racional& obj)
{
    return Racional(n*obj.num, obj.den);
}

Racional Racional::operator/(const Racional& obj) const
{
    return Racional(num*obj.den, den*obj.num);
}

Racional Racional::operator/(const int& n) const
{
    return Racional(num, den*n);
}

Racional operator/(const int& n, const Racional& obj)
{
    return Racional(n*obj.den, obj.num);
}

bool Racional::operator==(const Racional& obj) const
{
    return (num==obj.num&&den==obj.den);
}

Racional& Racional::operator+=(const Racional& obj)
{
    if(den==obj.den)
        num += obj.num;
    else
    {
        num = num * obj.den + obj.num * den;
        den *= obj.den;
    }
    simplificar();
    arreglarSigno();
    return *this;
}

Racional& Racional::operator+=(const int& n)
{
    num += (n * den);
    simplificar();
    arreglarSigno();
    return *this;
}

Racional& Racional::operator-=(const Racional& obj)
{
    if(den==obj.den)
        num -= obj.num;
    else
    {
        num = num * obj.den - obj.num * den;
        den *= obj.den;
    }
    simplificar();
    arreglarSigno();
    return *this;
}

Racional& Racional::operator-=(const int& n)
{
    num -= (n * den);
    simplificar();
    arreglarSigno();
    return *this;
}

Racional& Racional::operator*=(const Racional& obj)
{
    num *= obj.num;
    den *= obj.den;
    simplificar();
    arreglarSigno();
    return *this;
}

Racional& Racional::operator*=(const int& n)
{
    num *= n;
    simplificar();
    arreglarSigno();
    return *this;
}

Racional& Racional::operator/=(const Racional& obj)
{
    num *= obj.den;
    den *= obj.num;
    simplificar();
    arreglarSigno();
    return *this;
}

Racional& Racional::operator/=(const int& n)
{
    den *= n;
    simplificar();
    arreglarSigno();
    return *this;
}

ostream& operator<<(ostream& os, Racional& obj)
{
    os<<obj.num;
    if(obj.den!=1)
        os<<"/"<<obj.den;
    os<<endl;
    return os;
}

istream& operator>>(istream& is, Racional& obj)
{
    int a, b;
    cout<<endl<<"Ingrese el numerador: ";
    is>>a;
    cout<<endl<<"Ingrese el denominador: ";
    is>>b;
    obj = Racional(a, b);
    return is;
}

