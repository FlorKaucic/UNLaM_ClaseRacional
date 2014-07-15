#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>

using namespace std;


class Racional
{
    private:
        int num;
        int den;
    public:
        Racional(int=0, int=1);
        virtual ~Racional();
        void simplificar();
        void arreglarSigno();
        Racional& operator=(const Racional&);
        Racional operator+(const Racional&) const;
        Racional operator+(const int&) const;
        friend Racional operator+(const int&, const Racional&);
        Racional operator-(const Racional&) const;
        Racional operator-(const int&) const;
        friend Racional operator-(const int&, const Racional&);
        Racional operator*(const Racional&) const;
        Racional operator*(const int&) const;
        friend Racional operator*(const int&, const Racional&);
        Racional operator/(const Racional&) const;
        Racional operator/(const int&) const;
        friend Racional operator/(const int&, const Racional&);
        bool operator==(const Racional&) const;
        Racional& operator+=(const Racional&);
        Racional& operator+=(const int&);
        Racional& operator-=(const Racional&);
        Racional& operator-=(const int&);
        Racional& operator*=(const Racional&);
        Racional& operator*=(const int&);
        Racional& operator/=(const Racional&);
        Racional& operator/=(const int&);
        friend ostream& operator<<(ostream&, Racional&);
        friend istream& operator>>(istream&, Racional&);
};

#endif // RACIONAL_H
