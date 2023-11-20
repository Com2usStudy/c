#include <iostream>
using namespace std;

int &test()
{
    int a = 2;
    return a;
}

int main()
{
    int b = test();
    b = 3;
    return 0;
}