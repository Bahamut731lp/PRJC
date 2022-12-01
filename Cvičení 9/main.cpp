#include "String.cpp"
#include <iostream>
using namespace std;

int main()
{
    String str1(10);

    str1.set("Ahoj Svete 1234568789");
    // cout << str1.getLength() << endl;
    str1.print();

    return 0;
}