#include <iostream>
#include <fstream>
#include "CW.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    /*ofstream fin("A.txt");
    ifstream fread;
    char a[20];
    fin << "AAAAA";
    fin.close();
    fread.open("A.txt");
    fread.get(a, 10);
    fread.close();
    cout << a;*/
    int n = 10;
    human* b = new human("a", "b", "c", 12, 1, 1, 1);
    b->setName("З", "Б", "Олегович");
    b->getInf();
    b->setFingerprint(123456);
   /* b->getAllInf();
    human* a = new human("A", "B", "D", 15, 1, 1, 1);
    a->getAllInf();
    if(a->compare(b)) cout << "Норм";*/
    return 0;
}
