#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;


class Technics {
public:

    virtual void getInfo() = 0;
    virtual void addToDatabase() = 0;
};

class ElectricalAppliance : public Technics {
protected:

    string name = " ";
    string manufacturer = " ";
    int yearOfProduction = 0;
    double cost = 0;

public:
    string status = "ok";
    void getInfo()override {};
    void addToDatabase() override {};

    void getAllInfo()
    {
        if (name == " ")
        {
            cout << "Основная информация не заполнена!" << endl;
        }
        else cout << "Название: " << name << ", Производитель: " << manufacturer << ", Год производства: " << yearOfProduction << ", Цена: " << cost << endl;
    }
    void getStatus()
    {
        cout << "Статус техники: " << status << endl;
    }
    void setStatus(string stat)
    {
        status = stat;
        cout << "Новый статус объекта: " << status << endl;
    }
    int getCost()
    {
        return cost;
    }

    int getYear()
    {
        return yearOfProduction;
    }
};

class TV : public ElectricalAppliance {
private:

    string resolution;
    string displayType;

public:
    int type = 1;
    TV()
    {
        cout << "Введите имя устройства: ";
        cin >> name;
        cout << " Введите производителя: ";
        cin >> manufacturer;
        cout << " Введите год производства: ";
        cin >> yearOfProduction;
        cout << " Введите цену: ";
        cin >> cost;
        cout << "Введите разрешение: ";
        cin >> resolution;
        cout << "Введите тип дисплея: ";
        cin >> displayType;
        cout << endl;
    }

    TV(string nameT, string manuf, int yearOfProd, double costt, string res, string displ)
    {
        name = nameT; manufacturer = manuf; yearOfProduction = yearOfProd; cost = costt; resolution = res;  displayType = displ;
    }


    void setInfo(string nameT, string manuf, int yearOfProd, double costt, double diag, string res, string displ)
    {
        name = nameT; manufacturer = manuf; yearOfProduction = yearOfProd; cost = costt; resolution = res;  displayType = displ;
    }

    void getInfo() override
    {
        cout << "TV Разрешение: " << resolution << ", тип дисплея:" << displayType << endl;
    }


};

class WashingMachine : public ElectricalAppliance {
private:
    string maxLoad;
    string loadingType;
public:
    int type = 2;
    void setInfo(string nameT, string manuf, int yearOfProd, double cost, string maxl, string loadT)
    {
        name = nameT; manufacturer = manuf; yearOfProduction = yearOfProd; cost = cost; maxLoad = maxl; loadingType = loadT;
    }
    void getInfo() override
    {
        cout << "Максимальная загрузка: " << maxLoad << ", Тип загрузки: " << loadingType << endl;
    }

    WashingMachine(string nameT, string manuf, int yearOfProd, double costt, string Temp1, string Temp2)
    {
        name = nameT; manufacturer = manuf; yearOfProduction = yearOfProd; cost = costt; maxLoad = Temp1;  loadingType = Temp2;
    }

    WashingMachine()
    {
        cout << "Введите имя устройства: ";
        cin >> name;
        cout << " Введите производителя: ";
        cin >> manufacturer;
        cout << " Введите год производства: ";
        cin >> yearOfProduction;
        cout << " Введите цену: ";
        cin >> cost;
        cout << "Введите максимальную загрузку: ";
        cin >> maxLoad;
        cout << "Введите тип загрузки: ";
        cin >> loadingType;
        cout << endl;
    }
};

class OtherThings : public ElectricalAppliance {
protected:
    string applianceType;
    string energyConsumption;
public:
    int type = 3;
    void setInfo(string nameT, string manuf, int yearOfProd, double cost, string appType, string energyCon)
    {
        name = nameT; manufacturer = manuf; yearOfProduction = yearOfProd; cost = cost; applianceType = appType; energyConsumption = energyCon;
    }

    void getInfo() override
    {
        cout << "Тип устройства: " << applianceType << ", Потребление энергии:" << energyConsumption << endl;
    }

    OtherThings(string nameT, string manuf, int yearOfProd, double costt, string Temp1, string Temp2)
    {
        name = nameT; manufacturer = manuf; yearOfProduction = yearOfProd; cost = costt; applianceType = Temp1;  energyConsumption = Temp2;
    }

    OtherThings()
    {
        cout << "Введите имя устройства: ";
        cin >> name;
        cout << " Введите производителя: ";
        cin >> manufacturer;
        cout << " Введите год производства: ";
        cin >> yearOfProduction;
        cout << " Введите цену: ";
        cin >> cost;
        cout << "Введите тип устройства: ";
        cin >> applianceType;
        cout << "Введите потребление энергии: ";
        cin >> energyConsumption;
        cout << endl;
    }
};


//////////////////////////////////////         USERS
class User {
protected:
    string username;
    string password;

public:
    User(string username, string password) : username(username), password(password) {}

    bool login(string tryingPass) {
        string actualPass = password;
        if (tryingPass == actualPass)
        {
            return 1;
        }
        else return 0;

    }


    virtual void displayInfo() = 0;
};

class Administrator : public User {
public:
    Administrator(string username, string password) : User(username, password) {}

    void ChangeStatus(ElectricalAppliance** temp, int l) {
        cout << endl << "Введите новый статус: ";
        string stat;
        cin >> stat;
        temp[l]->setStatus(stat);
    }

    void displayInfo() override {
        cout << "Вы авторизованы как администратор. Вы можете добавлять новые файлы и создавать отчёт и прочее. Буквы (А,Р) показывают кто имеет доступ к тем или иным функциям. А-администратор, Р-Рабочий." << endl;
    }
};

class Employee : public User {
public:
    Employee(string username, string password) : User(username, password) {}

    void displayInfo() override {
        cout << "Вы авторизованы как рабочий. Вы можете добавлять записи и выводить информацию и так далее.Буквы (А,Р) показывают кто имеет доступ к тем или иным функциям. А-администратор, Р-Рабочий." << endl;
    }

    void stata(ElectricalAppliance** objects, int count)
    {
        int costAll = 0;
        int yearAll = 0;
        for (int i = 0; i < count; i++)
        {
            costAll += objects[i]->getCost();
            yearAll += objects[i]->getYear();
        }
        cout << "Средняя цена всех объектов равна: " << costAll / count << " . Средний год производства: " << yearAll / count << endl;
    }
};

///////////////////////////////////////////////////////////////////////// РАБОТА С ФАЙЛАМИ

void readFromFile(std::string fileName, ElectricalAppliance** objects, int n) {
    ifstream file(fileName);
    if (file.is_open())
    {
        std::string line;
        int i = 0;

        while (getline(file, line) && i < n) {
            std::istringstream iss(line);
            int type;
            std::string name, manufacture, T1, T2, stat;
            int year;
            double cost;
            if (iss >> type >> name >> manufacture >> year >> cost >> T1 >> T2 >> stat) {
                switch (type) {
                case 1:
                    objects[i] = new TV(name, manufacture, year, cost, T1, T2);
                    objects[i]->status = stat;
                    break;
                case 2:
                    objects[i] = new WashingMachine(name, manufacture, year, cost, T1, T2);
                    objects[i]->status = stat;
                    break;
                case 3:
                    objects[i] = new OtherThings(name, manufacture, year, cost, T1, T2);
                    objects[i]->status = stat;
                    break;
                }
                i++;
            }
        }
        file.close();
    }
    else cout << "Файл не найден. Создайте новый или введите название корректно.  " << endl;

}

void writeToFile(string fileName, int type, string name, string manufacture, int year, double cost, string T1, string T2, string stat) {
    ofstream file(fileName, ios::app);
    if (file.is_open())
    {
        file << type << " " << name << " " << manufacture << " " << year << " " << cost << " " << T1 << " " << T2 << " " << stat << endl;
        file.close();
    }
    else cout << "Файл не найден. Создайте новый или введите название корректно. " << endl;
}


int countOfLine(string fileName)
{
    ifstream file(fileName);
    int count = 0;
    string line;
    while (getline(file, line)) {
        ++count;
    }
    return count;
}

/////////////////////////////////////////////////////////////////

int menu()
{
    cout << "Выберите: " << endl;
    cout << "1. Войти как администратор" << endl; //
    cout << "2. Войти как рабочий" << endl; // 
    cout << "3. Создать файл (A)" << endl; //
    cout << "4. Создать запись (A,P)" << endl; //
    cout << "5. Вывод информации (A,P)" << endl;//
    cout << "6. Задать статус (A)" << endl; // 
    cout << "7. Статистика (А,Р)" << endl; // 
    cout << "8. Выход" << endl; // 

    char c;

    do {
        c = _getch();
    } while (c - '0' < 0 || c - '0' > 8);

    return c - '0';
}
//////////////////////////////////////////////////////////
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string namefile;
    Administrator admin("admin", "admin123");
    Employee employee("employee", "employee123");
    string adminPassword, employeePassword;
    int n = 20; // кол-во мест на складе по стандарту
    ////////////////////////////////////////////////////            ВВОД КОЛ-ВА МЕСТ

    int choice;
    cout << "Кол-во мест на складе по умолчанию = 20. Для изменения значения нажмите 1, иначе нажмите 2." << endl;
    cin >> choice;
    switch (choice)
    {
    case 1: {
        cout << "Введите новое кол-во мест: ";
        cin >> n;
        cout << endl;
        break;
    }
    case 2: {

        break; }

    default: "Ввод некоректен. Принято значение по умолчанию.";
    }
    cout << "Текущее кол-во мест на складе:" << n << endl;

    ElectricalAppliance** objects = new ElectricalAppliance * [n];


    /////////////////////////////////////////////// ПОДГРУЗКА ДАННЫХ ИЗ ФАЙЛА


    cout << "Введите название файла с базой данных" << endl;
    cin >> namefile;
    readFromFile(namefile, objects, n);


    /////////////////////////////////////////////////////////////\



    while (true)
    {
        switch (menu())
        {

        case 1: { // вход админом
            cout << " 1. Зайти как администратор" << endl;
            cout << "Введите пароль: ";
            cin >> adminPassword;
            if (admin.login(adminPassword)) {

                // admin.generateReport();
                // admin.displayInfo();
            }
            else {
                cout << "Пароль неверный." << endl;
            }
            cout << endl;
            admin.displayInfo();
            break;
        }

        case 2:
        { // вход рабочим
            cout << "Введите пароль рабочего: ";
            cin >> employeePassword;
            if (employee.login(adminPassword)) {
                //
            }
            else {
                cout << "Некоректный пароль." << endl;
            }
            employee.displayInfo();
            break;
        }

        case 3:
        { // Создание нового файла
            if (admin.login(adminPassword) || employee.login(employeePassword)) {
                cout << "Введите название файла: ";
                cin >> namefile;
                ofstream outfile(namefile);
                outfile.close();
                cout << "Файл создан успешно, вы можете добавить записи в него." << endl;
            }
            else cout << "Нет доступа. Войдите как админ или рабочий." << endl;
        } break;

        case 4: // создать запись( файл+объект)
        {
            if (admin.login(adminPassword) || employee.login(employeePassword))
            {
                int type;
                cout << "Выберите тип техники: 1- Телевизор. 2- Стиральная машина. 3-Другая техника: ";
                cin >> type;
                cout << endl;
                cout << "Введите имя устройства: ";
                string namet;
                cin >> namet;
                cout << endl;
                cout << " Введите производителя: ";
                string manufacturert;
                cin >> manufacturert;
                cout << endl;
                cout << " Введите год производства: ";
                int yearOfProduction;
                cin >> yearOfProduction;
                cout << endl;
                cout << " Введите цену: ";
                double cost;
                cin >> cost;
                cout << endl;
                cout << "Введите первое свойство в зависимости от устройства (Разрешение/ Mаксимальная загрузка/ Tип устройства): ";
                string tt1;
                cin >> tt1;
                cout << endl;
                cout << "Введите Второе свойство в зависимости от устройства (Тип дисплея/ Тип загрузки/ Потребление энергии): ";
                string tt2;
                cin >> tt2;
                cout << endl;
                cout << "Введите статус объекта: ";
                string statt;
                cin >> statt;
                cout << endl;
                writeToFile(namefile, type, namet, manufacturert, yearOfProduction, cost, tt1, tt2, statt);
                switch (type) {
                case 1:
                    objects[countOfLine(namefile) + 1] = new TV(namet, manufacturert, yearOfProduction, cost, tt1, tt2);
                    objects[countOfLine(namefile) + 1]->status = statt;
                    break;
                case 2:
                    objects[countOfLine(namefile) + 1] = new WashingMachine(namet, manufacturert, yearOfProduction, cost, tt1, tt2);
                    objects[countOfLine(namefile) + 1]->status = statt;
                    break;
                case 3:
                    objects[countOfLine(namefile) + 1] = new OtherThings(namet, manufacturert, yearOfProduction, cost, tt1, tt2);
                    objects[countOfLine(namefile) + 1]->status = statt;
                    break;
                }

            }
            else { cout << "Доступ к созданию записей есть только у администратора." << endl; }

            break;
        }
        case 5: // вывод на экран
        {
            if (admin.login(adminPassword) || employee.login(employeePassword))
            {
                int vibor;
                cout << "Вывод на экран. Выберите режим: 1- Вывод свойств техники. 2- Вывод основной информации+статус. 3- Вывод всей информации" << endl;
                cin >> vibor;
                readFromFile(namefile, objects, n);
                switch (vibor)
                {
                case 1:
                {
                    for (int i = 0; i < countOfLine(namefile); i++)
                    {
                        cout << i + 1 << ") ";
                        objects[i]->getInfo();

                    }
                    cout << endl;
                    break;
                }
                case 2:
                {
                    for (int i = 0; i < countOfLine(namefile); i++)
                    {
                        cout << i + 1 << ") ";
                        objects[i]->getAllInfo();
                        objects[i]->getStatus();
                        cout << endl;

                    }
                    cout << endl;
                    break;
                }
                case 3:
                {
                    for (int i = 0; i < countOfLine(namefile); i++)
                    {
                        cout << i + 1 << ") ";
                        objects[i]->getAllInfo();
                        objects[i]->getInfo();
                        objects[i]->getStatus();
                        cout << endl;
                    }
                    cout << endl;
                    break;
                }
                default: cout << "Неверный ввод" << endl; break;

                }
                break;
            }
            else cout << "Войдите как администратор или как рабочий." << endl;
            break;
        }
        case 6:
        {
            cout << "Выберите номер объекта для изменения статуса:" << endl;
            readFromFile(namefile, objects, n);
            for (int i = 0; i < countOfLine(namefile); i++)
            {
                cout << i << ") ";
                objects[i]->getAllInfo();
                objects[i]->getInfo();
                objects[i]->getStatus();
                cout << endl;
            }
            int l;
            cout << "Номер объекта: ";
            cin >> l;
            if (l >= countOfLine(namefile)) cout << "Неверный ввод" << endl;
            else admin.ChangeStatus(objects, l);
        }


        case 7:
        {
            if (admin.login(adminPassword) || employee.login(employeePassword))
            {
                readFromFile(namefile, objects, n);
                cout << "Статистика:" << endl;
                employee.stata(objects, countOfLine(namefile));



                break;
            }
            else cout << "Нет доступа, войдите как админ или рабочий." << endl;
        }

        case 8:
            cout << " 6. Выход" << endl;

            return 0;
            break;

        default: cout << "Выберите правильно" << endl;
        }
        //cout << endl << "Нажмите любую клавишу";
        //_getch();
        system("pause");
        system("cls");

    }

    delete[] objects;
    return 0;
}