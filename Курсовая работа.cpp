#include <iostream>
#include <fstream>
#include "CW.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    int n = 10;
    human* b = new human("Симэн", "Векторович", "Викторович", 12, 1, 1, 1);
    b->popIris(0);
    b->getInf();
    b->setIris(123456);
    b->getPass(b);
    return 0;
}
