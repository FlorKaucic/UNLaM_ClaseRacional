#include "Racional.h"

#include <iostream>

using namespace std;

#define aMayus(x) ((x)>'a'&&(x)<'z')?(x)-32:(x)

char menuCuentas();

int main()
{
    Racional num1(48, 36);
    Racional num2(9, 4);
    Racional num3;
    Racional num4;
    Racional num5;

    cout << endl << "Clase Racional" << endl;

    cout << endl << "num1(48, 36)" << endl << num1;
    cout << endl << "num2(9, 3)" << endl << num2;
    cout << endl << "num3" << endl << num3;
    cout << endl << "num4" << endl << num4;

    /*
    cin >> num3 >> num4;
    cout << endl << "num3" << endl << num3;
    cout << endl << "num4" << endl << num4;
    */

    switch(menuCuentas())
    {
    case 'S':
        num5 = num1+num2;
        cout << endl << "num1 + num2" << endl << num5;
        num5 = num1+2;
        cout << endl << "num1 + 2" << endl << num5;
        num5 = 5+num1;
        cout << endl << "5 + num1" << endl << num5;
        break;
    case 'R':
        num5 = num1-num2;
        cout << endl << "num1 - num2" << endl << num5;
        num5 = num1-2;
        cout << endl << "num1 - 2" << endl << num5;
        num5 = 5-num1;
        cout << endl << "5 - num1" << endl << num5;
        break;
    case 'M':
        num5 = num1*num2;
        cout << endl << "num1 * num2" << endl << num5;
        num5 = num1*2;
        cout << endl << "num1 * 2" << endl << num5;
        num5 = 5*num1;
        cout << endl << "5 * num1" << endl << num5;
        break;
    case 'D':
        num5 = num1/num2;
        cout << endl << "num1 / num2" << endl << num5;
        num5 = num1/2;
        cout << endl << "num1 / 2" << endl << num5;
        num5 = 5/num1;
        cout << endl << "5 / num1" << endl << num5;
        break;
    }



    return 0;
}

char menuCuentas()
{
    char opc;
    do
    {
        cout << endl << endl;
        cout << "Elija una opcion:";
        cout << endl << "S. Suma";
        cout << endl << "R. Resta";
        cout << endl << "M. Multiplicacion";
        cout << endl << "D. Division";
        cout << endl << endl;
        cout << "Opcion: ";
        cin >> opc;
        opc = aMayus(opc);
    }while(opc!='S'&&opc!='R'&&opc!='M'&&opc!='D');
    return opc;
}
