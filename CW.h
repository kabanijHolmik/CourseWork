#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <format>
#include <cstdio>
#include <ctime>
using namespace std;

fstream libF, libI, libFa;//файл содержащий все биометрические данные, после будет использоваться для метода compare
class fingerprint {
public:
    fingerprint() {}
    fingerprint(int amount) {
        int k;
        for (int i = 0; i < amount; i++) {
            cout << "Введите отпечаток пальца " << i + 1 << " ";
            cin >> k;
            fingerprintNormalisation(k);
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
        fingerprintNormalisation(x);
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
    virtual void popFingerprint() {//Удаляет последний элемент
        fingerprintID--;
        a.pop_back();
    }
    virtual void popFingerprint(int ID) { //Удаляет элемент по ID
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
    void fingerprintNormalisation(int& x) {
        if (x < 1000) {
            x *= 10;
            fingerprintNormalisation(x);
        }
        if (x > 9999) {
            x /= 10;
            fingerprintNormalisation(x);
        }
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
            irisNormalisation(k);
            setIris(k);
        }
        cout << endl;
    }
protected:
    vector<int> a;
    int eye;
    int irisID = 0;
public:
    virtual void setIris(int x) {
        irisNormalisation(x);
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
    virtual void popIris() {
        irisID--;
        a.pop_back();
    }
    virtual void popIris(int ID) {
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
    void irisNormalisation(int& x) {
        if (x < 10000) {
            x *= 10;
            irisNormalisation(x);
        }
        if (x > 99999) {
            x /= 10;
            irisNormalisation(x);
        }
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
            facialNormalisation(k);
            setFacialGeometry(k);
        }
        cout << endl;
    }
protected:
    vector<int> a;
    int face;
    int facialGeometryID = 0;
public:
    virtual void setFacialGeometry(int x) {
        facialNormalisation(x);
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
    virtual void popFacialGeometry() {
        facialGeometryID--;
        a.pop_back();
    }
    virtual void popFacialGeometry(int ID) {
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
    void facialNormalisation(int& x) {
        if (x < 100000) {
            x *= 10;
            facialNormalisation(x);
        }
        if (x > 999999) {
            x /= 10;
            facialNormalisation(x);
        }
    }
};

class human : public fingerprint, public iris, public facialGeometry {
public:
    human() : fingerprint(), iris(), facialGeometry() {}
    human(int n1, int n2, int n3) : fingerprint(n1), iris(n2), facialGeometry(n3) {}
    human(const char(*n), const char(*s), const char(*p), int age) : fingerprint(), iris(), facialGeometry() {
        name = n;
        ifstream check;
        check.open(format("Res/{}.txt", name));
        if (check) {
            remove(format("Res/{}.txt", name).c_str());
        }
        this->age = age;
        strcpy_s(surname, s);
        strcpy_s(patronymic, p);
        file.open(format("Res/{}.txt", name));
        file.close();
        cout << "Человек успешно добавлен" << endl << endl;
    }
    human(const char(*n), const char(*s), const char(*p), int age, int n1, int n2, int n3) : fingerprint(n1), iris(n2), facialGeometry(n3) {
        name = n;
        ifstream check;
        check.open(format("Res/{}.txt", name));
        if (check) {
            remove(format("Res/{}.txt", name).c_str());
        }
        this->age = age;
        name = n;
        strcpy_s(surname, s);
        strcpy_s(patronymic, p);
        file.open(format("Res/{}.txt", name), ios:: out);
        libF.open("Lib/fingerprint.txt", ios::app);
        if (!libF) cout << "Сууука";
        file << "Отпечатки пальцев: " << endl;
        for (int i = 0; i < n1; i++) {
            file << format("{}){}", i + 1, fingerprint::getFingerprint(i)) << endl;
            libF << fingerprint::getFingerprint(i) << " ";
        } 
        libI.open("Lib/iris.txt", ios::app);
        if (!libI) cout << "бля";
        file << "Радужка глаза: " << endl;
        for (int i = 0; i < n2; i++) {
            file << format("{}){}", i + 1, iris::getIris(i)) << endl;
            libI << iris::getIris(i) << " ";
        }
        libFa.open("Lib/facial.txt", ios::app);
        if (!libFa) cout << "пиздос";
        file << "Геометрия лица: " << endl;
        for (int i = 0; i < n3; i++) {
            file << format("{}){}", i + 1, facialGeometry::getFacialGeometry(i)) << endl;
            libFa << facialGeometry::getFacialGeometry(i) << " ";
        }
        file.close();
        libF.close();
        libI.close();
        libFa.close();
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
    void rewriteFile() {
        file.open(format("Res/{}.txt", name), ios::out);
        file << "Отпечатки пальцев: " << endl;
        for (int i = 0; i < fingerprint::fingerprintID; i++) {
            file << format("{}){}", i + 1, fingerprint::getFingerprint(i)) << endl;
        }
        file << "Радужка глаза: " << endl;
        for (int i = 0; i < iris::irisID; i++) {
            file << format("{}){}", i + 1, iris::getIris(i)) << endl;
        }
        file << "Геометрия лица: " << endl;
        for (int i = 0; i < facialGeometry::facialGeometryID; i++) {
            file << format("{}){}", i + 1, facialGeometry::getFacialGeometry(i)) << endl;
        }
        file.close();
    }
    void getInf() {
        cout << "Имя: " << this->name << endl;
        cout << "Фамилия: " << this->surname << endl;
        cout << "Отчество: " << this->patronymic << endl;
        cout << "Возраст: " << this->age << endl << endl;
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
        strcpy_s(tmp, n);
        if (rename(format("Res/{}.txt", name).c_str(), format("Res/{}.txt", name).c_str()) == 0);
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
        rewriteFile();
        libF.open("Lib/fingerprint.txt", ios::app);
        libF << format("{} ", x);
        libF.close();
    }
    void popFingerprint() {
        fingerprint::popFingerprint();
        rewriteFile();
    }
    void popFingerprint(int ID) {
        fingerprint::popFingerprint(ID);
        rewriteFile();
    }
    void setIris(int x) {
        iris::setIris(x);
        rewriteFile();
        libI.open("Lib/iris.txt", ios::app);
        libI << format("{} ", x);
        libI.close();
    }
    void popIris() {
        iris::popIris();
        rewriteFile();
    }
    void popIris(int ID) {
        iris::popIris(ID);
        rewriteFile();
    }
    void setFacialGeometry(int x) {
        facialGeometry::setFacialGeometry(x);
        rewriteFile();
        libFa.open("Lib/facial.txt", ios::app);
        libFa << format("{} ", x);
        libFa.close();
    }
    void popFacialGeometry() {
        facialGeometry::popFacialGeometry();
        rewriteFile();
    }
    void popFacialGeometry(int ID) {
        facialGeometry::popFacialGeometry(ID);
        rewriteFile();
    }
    void getPass(human* b) {
        if (compare(b)) {
            time_t seconds, seconds24;
            time(&seconds);
            seconds24 = seconds + 60*60*24;
            string dmt = ctime(&seconds);
            string dmt24 = ctime(&seconds24);
            fstream pass;
            pass.open(format("Res/{}_PASS.txt", name), ios::out);
            pass << format("Пропуск для {} {} {}:",this->surname, this->name, this->patronymic) << endl;
            pass << "\nДействует 24 часа с момента выдачи: \n" << dmt << "\nДействителен по:\n" << dmt24;
        }
    }
};
