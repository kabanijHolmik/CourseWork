#include <iostream>
#include <fstream>
#include <vector>
#include <format>
#include <cstdio>
using namespace std;

class fingerprint {
public:
    fingerprint() {}
    fingerprint(int amount) {
        int k;
        for (int i = 0; i < amount; i++) {
            cout << "Введите отпечаток пальца " << i + 1 << " ";
            cin >> k;
            setFingerprint(k);
        }
        cout << endl;
    }
protected:
    vector<int> a;
    int finger;
    int fingerprintID = 0;
public:
    virtual void setFingerprint(int x) { //устанавливает отпечаток пальца
        this->finger = x;
        a.push_back(this->finger);
        this->fingerprintID++;
    }
    int getFingerprint(int number) { //выодит отпечаток пальца, находящийся в массиве под номером number
        if (number >= a.size() || number < 0) {
            cout << "Такого элемента нет" << endl;
            return NULL;
        }
        return a.at(number);
    }
    void getFingerprint() { //выоводит все отпечатки пальцев
        for (int i = 0; i < a.size(); i++) {
            cout << "Отпечаток пальца " << i << ": " << a.at(i) << endl;
        }
    }
    bool compareFingerprints(int x) {//сравнение отпечатка со всеми внесенными в базу
        bool res = 0;
        for (int i = 0; i < a.size(); i++) {
            if (x == a.at(i)) {
                res = 1;
                return res;
            }
        }
        return res;
    }
    void popFingerprint() {//Удаляет последний элемент
        fingerprintID--;
        a.pop_back();
    }
    void popFingerprint(int ID) { //Удаляет элемент по ID
        fingerprintID--;
        a.erase(a.begin() + ID);
    }
    int searchFingerprint(int x) {
        for (int i = 0; i < a.size(); i++) {
            if (x == a.at(i)) return i;
        }
        return -1;
    }
    int lengthFingerPrint() {
        return a.size();
    }

};

class iris {
public:
    iris() {}
    iris(int amount) {
        int k;
        for (int i = 0; i < amount; i++) {
            cout << "Просканируйте радужку глаза " << i + 1 << " ";
            cin >> k;
            setIris(k);
        }
        cout << endl;
    }
protected:
    vector<int> a;
    int eye;
    int irisID = 0;
public:
    void setIris(int x) {
        this->eye = x;
        a.push_back(this->eye);
        this->irisID++;
    }
    int getIris(int number) {
        if (number >= a.size() || number < 0) {
            cout << "Такого элемента нет" << endl;
            return NULL;
        }
        return a.at(number);
    }
    void getIris() {
        for (int i = 0; i < a.size(); i++) {
            cout << "Радужка глаза " << i << ": " << a.at(i) << endl;
        }
    }
    bool compareIris(int x) {
        bool res = 0;
        for (int i = 0; i < a.size(); i++) {
            if (x == a.at(i)) {
                res = 1;
                return res;
            }
        }
        return res;
    }
    void popIris() {
        irisID--;
        a.pop_back();
    }
    void popIris(int ID) {
        irisID--;
        a.erase(a.begin() + ID);
    }
    int searchIris(int x) {
        for (int i = 0; i < a.size(); i++) {
            if (x == a.at(i)) return i;
        }
        return -1;
    }
    int lengthIris() {
        return a.size();
    }
};

class facialGeometry {
public:
    facialGeometry() {}
    facialGeometry(int amount) {
        int k;
        for (int i = 0; i < amount; i++) {
            cout << "Просканируйте геомертию лица " << i + 1 << " ";
            cin >> k;
            setFacialGeometry(k);
        }
        cout << endl;
    }
protected:
    vector<int> a;
    int face;
    int facialGeometryID = 0;
public:
    void setFacialGeometry(int x) {
        this->face = x;
        a.push_back(this->face);
        this->facialGeometryID++;
    }
    int getFacialGeometry(int number) {
        if (number >= a.size() || number < 0) {
            cout << "Такого элемента нет" << endl;
            return NULL;
        }
        return a.at(number);
    }
    void getFacialGeometry() {
        for (int i = 0; i < a.size(); i++) {
            cout << "Геометрия лица " << i << ": " << a.at(i) << endl;
        }
    }
    bool compareFacialGeometry(int x) {
        bool res = 0;
        for (int i = 0; i < a.size(); i++) {
            if (x == a.at(i)) {
                res = 1;
                return res;
            }
        }
        return res;
    }
    void popFacialGeometry() {
        facialGeometryID--;
        a.pop_back();
    }
    void popFacialGeometry(int ID) {
        facialGeometryID--;
        a.erase(a.begin() + ID);
    }
    int searchFacialGeometry(int x) {
        for (int i = 0; i < a.size(); i++) {
            if (x == a.at(i)) return i;
        }
        return -1;
    }
    int lengthFacialGeometry() {
        return a.size();
    }
};

class human : public fingerprint, public iris, public facialGeometry {
public:
    human() : fingerprint(), iris(), facialGeometry() {}
    human(int n1, int n2, int n3) : fingerprint(n1), iris(n2), facialGeometry(n3) {}
    human(const char(*n), const char(*s), const char(*p), int age) : fingerprint(), iris(), facialGeometry() {
        this->age = age;
        name = n;
        strcpy_s(surname, s);
        strcpy_s(patronymic, p);
        file.open(format("{}.txt", *n));
        file.close();
        cout << "Человек успешно добавлен" << endl << endl;
    }
    human(const char(*n), const char(*s), const char(*p), int age, int n1, int n2, int n3) : fingerprint(n1), iris(n2), facialGeometry(n3) {
        this->age = age;
        name = n;
        strcpy_s(surname, s);
        strcpy_s(patronymic, p);
        file.open(format("{}.txt", *n), ios:: out);
        file << "Отпечатки пальцев: " << endl;
        for (int i = 0; i < n1; i++) {
            file << format("{}){}", i + 1, fingerprint::getFingerprint(i)) << endl;
        } 
        file << "Радужка глаза: " << endl;
        for (int i = 0; i < n2; i++) {
            file << format("{}){}", i + 1, iris::getIris(i)) << endl;
        }
        file << "Геометрия лица: " << endl;
        for (int i = 0; i < n3; i++) {
            file << format("{}){}", i + 1, facialGeometry::getFacialGeometry(i)) << endl;
        }
        file.close();
        cout << "Человек успешно добавлен" << endl << endl;
    }
private:
    int ID = 0;
    int age;
    string name;
    char surname[20];
    char patronymic[20];
    fstream file;
public:
    void getInf() {
        cout << "Имя: " << this->name << endl;
        cout << "Фамилия: " << this->surname << endl;
        cout << "Отчество: " << this->patronymic << endl;
        cout << "Возраст: " << this->age << endl;
    }
    void getAllInf() {
        cout << "Имя: " << this->name << endl;
        cout << "Фамилия: " << this->surname << endl;
        cout << "Отчество: " << this->patronymic << endl;
        cout << "Возраст: " << this->age << endl << endl;
        this->getFingerprint();
        this->getIris();
        this->getFacialGeometry();
    }
    void setName(const char(*n), const char(*s), const char(*p)) {
        char tmp[20];
        char tmp1;
        strcpy_s(tmp, n);
        if (rename(format("{}.txt", this->name).c_str(), format("{}.txt", tmp).c_str()) == 0);
        else return;
        name = n;
        strcpy_s(surname, s);
        strcpy_s(patronymic, p);
    }
    void setAge(int a) {
        this->age = a;
    }
    bool compare(human* b) {
        for (int i = 0; i < this->lengthFingerPrint(); i++) {
            for (int j = 0; j < b->lengthFingerPrint(); j++) {
                if (this->getFingerprint(i) == b->getFingerprint(j)) return true;
            }
        }
        for (int i = 0; i < this->lengthIris(); i++) {
            for (int j = 0; j < b->lengthIris(); j++) {
                if (this->getIris(i) == b->getIris(j)) return true;
            }
        }
        for (int i = 0; i < this->lengthFacialGeometry(); i++) {
            for (int j = 0; j < b->lengthFacialGeometry(); j++) {
                if (this->getFacialGeometry(i) == b->getFacialGeometry(j)) return true;
            }
        }
        return false;
    }
    void setFingerprint(int x) {
        fingerprint::setFingerprint(x);
        file.open(format("{}.txt", name), ios::out);
        file << "Отпечатки пальцев: " << endl;
        for (int i = 0; i < fingerprint:: fingerprintID; i++) {
            file << format("{}){}", i + 1, fingerprint::getFingerprint(i)) << endl;
        }
        file << "Радужка глаза: " << endl;
        for (int i = 0; i < iris:: irisID; i++) {
            file << format("{}){}", i + 1, iris::getIris(i)) << endl;
        }
        file << "Геометрия лица: " << endl;
        for (int i = 0; i < facialGeometry:: facialGeometryID; i++) {
            file << format("{}){}", i + 1, facialGeometry::getFacialGeometry(i)) << endl;
        }
        file.close();
    }
};
