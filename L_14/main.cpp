#include <iostream>

using namespace std;

int main()
{
    float a = 5;
    int c1;
    c1 = a/2.0;
    cout<<"1. c1=" << c1 <<endl;

    int a2 = 7;
    float c2;
    c2 = a2/2.0;
    cout<<"2. c2=" << c2 <<endl;

    unsigned char a3 = 17;
    unsigned char c3;
    c3 = a3*a3;
    cout<<"3. c3=" << c3 <<endl;

    unsigned short a4=10;
    unsigned char c4;
    c4 = a4 - 20;
    cout<<"4. c4=" << c4 <<endl;

    int j5, b5 = 5, a5 = 4 ;
    j5 = ++b5+a5++;
    cout<<"5. j1=" << j5 <<endl;

    cout<<"6. j2=" << 9 - (float)2 * ( 5 / 7 )  <<endl;
    cout<<"7. j3=" << 0x77 + 17 <<endl;

    return 0;
}
