#include <iostream>
#include <cstring>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "Covid_Management.h"
using namespace std;

void Doctor::vitals() {
    fstream filei("UserData.txt");
    //fstream ghu()
    file.open("UserData.txt", ios::ate);
    cout << "Enter username:";
    cin >> username;
    while (!filei.eof()) {
        getline(filei, usn);
        if (username == usn) {
            getline(filei, password);
            getline(filei, id);
            getline(filei, name);
            getline(filei, age);
            getline(filei, address);
            getline(filei, phone_no);
            cout << "CNIC:" << id << endl;
            cout << "Name:" << name << endl;
            cout << "Age:" << age << endl;
            cout << "Address:" << address << endl;
            cout << "Phone Number:" << phone_no << endl << endl;
            cout << "\t\t\t---Enter patient's vitals---" << endl;
            cout << "High Blood Pressure:";
            cin >> H_bloodP;
            cout << "Low Blood Pressure:";
            cin >> L_bloodP;
            cout << "Oxygen Level:";
            cin >> O_level;
            cout << "Gulucose Level:";
            cin >> CHO_level;
            filei << H_bloodP << endl;
            filei << L_bloodP << endl;
            filei << O_level << endl;
            filei << CHO_level << endl;
            filei.close();
        }
        else {
            getline(filei, password);
            getline(filei, id);
            getline(filei, name);
            getline(filei, age);
            getline(filei, address);
            getline(filei, phone_no);
        }
    }
    filei.close();
}

void user::Register()
{
    ofstream fileo;
    fileo.open("UserData.txt", ios::app);
    cout << "Enter username:";
    cin >> username;
    cout << "Enter password:";
    cin >> password;
    //condition
    file.open("UserData.txt");
    while (!file.eof())
    {
        file >> usn;
        file >> psd;
        if (username == usn && password == psd)
        {
            b = true;
            exit(0);
        }
        else
        {
            file >> id;
            file >> name;
            file >> age;
            file >> address;
            file >> phone_no;
        }
    }
    file.close();
    if (b == true)
    {
        cout << "This username is already registered-->" << endl;
    }
    else
    {
        add_patient_data();
    }
    fileo.close();
}

void user::applyfirst(string identity) {
    ofstream of;
    of.open("FirstVaccine.txt", ios::app);
    of << identity << endl;
    of.close();
}

void user::applysecond(string identity) {
    
    ifstream fin;
    string search;
    fin.open("FirstVaccine.txt");
    while (!fin.eof()) {
        fin >> search;
        if (search == identity) {
            ofstream of;
            of.open("SecondVaccine.txt", ios::app);
            of << id << endl;
            of.close();
            break;
        }
    }
    if (identity != search) {
        cout << "Take first dose." << endl;
    }
}

void user::usersmenu() {
    cout << "1- See your data" << endl;
    cout << "2- Apply First Vaccine" << endl;
    cout << "3- Apply Second Vacccine" << endl;
    cout << "Enter choice : ";
}

void user::login() {
    cout << "Enter username:";
    cin >> username;
    cout << "Enter password:";
    cin >> password;
    file.open("UserData.txt");
    while (!file.eof()){
        getline(file, usn);
        getline(file, psd);
        if (username == usn && password == psd){
            cout << "You are succeSsfully loged in-->" << endl;
            system("cls");
            usersmenu();
            cin >> choice;
            getline(file, id);
            while (choice != 0) {
                switch(choice){
                case 1:
                    cv.patient_show_data();
                    system("pause");
                    system("cls");
                    usersmenu();
                    cin >> choice;
                    break;
                case 2:
                    applyfirst(id);
                    system("pause");
                    system("cls");
                    usersmenu();
                    cin >> choice;
                    break;
                case 3:
                    
                    applysecond(id);
                    system("pause");
                    system("cls");
                    usersmenu();
                    cin >> choice;
                    break;
                case 4:
                    break;
                }
            }
            return;
        }
        else {
            getline(file, id);
            getline(file, name);
            getline(file, age);
            getline(file, address);
            getline(file, phone_no);
        }
        if (file.eof() && username != usn && password != psd) {
            cout << "You are not registered-->" << endl;
        }
    }
}

bool SuperAdmin::SuperAdmin_login(){
    system("cls");
    char SAName[20];
    char SAPass[20];
    int ch, i = 0, gen_captcha = 0, Input_captcha = 0;
    cout << "\t\tUser Name : ";
    cin >> SAName;
    cout << "\t\tPassword : ";
    while ((ch = _getch()) != 13)  {
        cout << "*";
        SAPass[i] = ch;
        i++;
    }
    SAPass[i] = '\0';
    srand(time(0));
    gen_captcha = rand();
    cout << endl << "Enter this number below : " << gen_captcha << endl;
    cout << "Enter the above number : ";
    cin >> Input_captcha;
    if ((strcmp(SAName, "Superadmin") == 0) && (strcmp(SAPass, "Superadmin") == 0) && (Input_captcha == gen_captcha))  {
        cout << endl << "\t\t\t\t | Veryfing Super Admin | " << endl;
        cout << "\t\t\t\t ";
        for (int s = 1; s < 5; s++){
            Sleep(500);
            cout << "......";
        }
        cout << endl << endl << "\t\t\t\t   Access Granted... ;)" << endl << endl;
        system("pause");
        return true;
    }
    else
    {
        cout << endl << "\t\t\t\t | Veryfing Super Admin | " << endl;
        cout << "\t\t\t\t ";
        for (int s = 1; s < 5; s++)
        {
            Sleep(400);
            cout << "......";
        }
        cout << endl << endl << "\t\t\t\t   Access Denied... :(" << endl << endl;
        system("pause");
        return false;
    }
}

void SuperAdmin::super_admin_menu()
{
    cout << "1- Add Doctor" << endl;
    cout << "2- Search Doctor Data" << endl;
    cout << "3- Display Doctor Data" << endl;
    cout << "4- Search Patient Data" << endl;
    cout << "5- Applied 1st Vaccine" << endl;
    cout << "6- Applied 2nd Vaccine" << endl;
    cout << "Enter Choice : ";
}

void SuperAdmin::applied_first_vaccine()
{
    system("cls");
    string counting;
    int count=0;
    ifstream fin;
    fin.open("FirstVaccine.txt");
    while (!fin.eof()) {
        fin >> counting;
        count++;
    }
    cout<<"Total number of applied first dose of vaccine are : " << count-1<<endl;
}

void SuperAdmin::applied_second_vaccine()
{
    system("cls");
    string counting1;
    int count1 = 0;
    ifstream fin1;
    fin1.open("FirstVaccine.txt");
    while (!fin1.eof()) {
        fin1 >> counting1;
        count1++;
    }
    cout << "Total number of applied first dose of vaccine are : " << count1-1<<endl;
}

void SuperAdmin::super_admin()
{
    system("cls");
    SuperAdmin S;
    bool login = S.SuperAdmin_login();
    if (login == true)
    {
        system("cls");
        super_admin_menu();
        cin >> super_admin_choice;
        while (super_admin_choice != 0)
        {
            switch (super_admin_choice)
            {
            case 1:
                add_doctor();
                system("pause");
                system("cls");
                super_admin_menu();
                cin >> super_admin_choice;
                break;
            case 2:
                search_doctor_data();
                system("pause");
                system("cls");
                super_admin_menu();
                cin >> super_admin_choice;
                break;
            case 3:
                display_doctor_data();
                system("pause");
                system("cls");
                super_admin_menu();
                cin >> super_admin_choice;
                break;
            case 4:
                patient_show_data();
                system("pause");
                system("cls");
                super_admin_menu();
                cin >> super_admin_choice;
                break;
            case 5:
                applied_first_vaccine();
                system("pause");
                system("cls");
                super_admin_menu();
                cin >> super_admin_choice;
                break;
            case 6:
                applied_second_vaccine();
                system("pause");
                system("cls");
                super_admin_menu();
                cin >> super_admin_choice;
                break;
            }
        }
    }
}

void Admin::menu()
{

    system("cls");
    int choice;
    cout << "1. ADMIN" << endl;
    cout << "2. USER" << endl;
    cout << "3. SUPER ADMIN" << endl;
    cout << "4. Doctor" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter Choice: " << endl;
    cin >> choice;
    switch (choice)
    {
    case 0:
        system("cls");
        exit(0);
    case 1:
        admin();
        break;
    case 2:
        usrr.User();
        break;
    case 3:
        sa.super_admin();
        break;
    case 4:
        d.vitals();
        break;

    }
}

void Admin::admin_menu()
{
    cout << " ADMIN MENU <<--" << endl;
    cout << " 1. Add Vaccine Stock" << endl;
    cout << " 2. Show Vaccine Center" << endl;
    cout << " 3. LOG OUT" << endl;
    cout << " Enter Choice: ";
}

void Admin::admin()
{
    system("cls");
    cout << "Enter user name : ";
    cin >> username;
    cout << "Enter Password :";
    cin >> password;
    if (username == "admin" && password == "admin")
    {
        system("cls");
        int admin_choice;
        // ADMIN MENU OPTIONS

        admin_menu();
        cin >> admin_choice;
        while (admin_choice != 0)
        {
            switch (admin_choice)
            {
            case 1:
                add_vaccine_stock();
                system("pause");
                system("cls");
                admin_menu();
                cin >> admin_choice;
                break;
            case 2:
                search_center();
                system("pause");
                system("cls");
                admin_menu();
                cin >> admin_choice;
                break;
            case 3:
                menu();
                break;
            }
        }
    }
    else {
        cout << "Wrong username or password" << endl;
        menu();
    }
}

void user::User()
{
    system("cls");
    cout << "Press 1 to register." << endl;
    cout << "Press 2 to login." << endl;
    cout << "Press 3 to exit." << endl;
    cin >> choice;
    if (choice == 1)
    {
        Register();
        system("pause");
        User();
    }
    else if (choice == 2)
    {
        login();
        system("pause");
        User();
    }
    else if (choice == 3)
    {
        exit(0);
    }
}

void Admin::menu1()
{
    system("cls");
    cout << "0. If You want to exit." << endl;
    cout << "1. If you want to create new warehouse." << endl;
    cout << "2. If you want to buy vaccine." << endl;
}

void Admin::add_vaccine_stock()
{

    menu1();
    cin >> choice;
    while (choice != 0) {
        switch (choice) {
        case 1:
            system("cls");
            cout << "\nEnter WareHouse Name:";
            cin.ignore();
            getline(cin, WR_Name);
            fname = "WareHouses\\" + WR_Name + ".txt";
            //cout<<fname;
            filei.open(fname.c_str());
            if (filei.is_open())
            {
                cout << "Warehouse of this name already exists, Chose another name." << endl;
                filei.close();
            }
            else
            {
                filei.close();
                fileo.open(fname.c_str(), std::ios_base::app);
            }
            system("pause");
            fileo.close();
            menu1();
            cin >> choice;
            break;

        case 2:
            system("cls");
            cout << "Enter WareHouse Name where you want to store vaccine:";
            cin.ignore();
            getline(cin, WR_Name);
            fname = "WareHouses\\" + WR_Name + ".txt";
            filei.open(fname.c_str());
            if (!filei.is_open() && filei.fail()) {
                cout << "WareHouse of such name does not exist, please create warehouse first." << endl;
                system("pause");
                filei.close();
            }
            else
            {
                if (filei.peek() == std::ifstream::traits_type::eof())
                {
                    j = 0;
                }
                else
                    j = 1;
                if (j > 0)
                {
                    while (!filei.eof()) {
                        filei >> BatchID;
                        filei >> current_cap;
                        filei >> NoOfDoses;
                        filei >> vacName;
                        filei >> BatchID;
                        filei >> exp_date;
                        filei >> price;
                        filei >> sup_ID;
                        WR_cap = current_cap;
                        //cout << j++;
                        break;
                    }
                }
                j++;
                cout << "WareHouse capacity: " << WR_cap << endl;
                if (WR_cap == 0) {
                    cout << "No more space in Warehouse.\nStore it in another warehouse." << endl;
                    system("pause");
                    break;
                }
                filei.close();
                fileo.open(fname.c_str(), std::ios_base::app);
                cout << "Enter Number of doses:";
                cin >> NoOfDoses;
                while (NoOfDoses > WR_cap) {
                    cout << "Invalid input\nAgain Enter number of doses." << endl;
                    cin >> NoOfDoses;
                }

                current_cap = WR_cap - NoOfDoses;
                cout << "Enter Vaccine Name:";
                cin.ignore();
                getline(cin, vacName);
                ++BatchID;
                cout << "Enter expirey date:";
                cin.ignore();
                getline(cin, exp_date);
                cout << "Enter price of whole vaccine batch:";
                cin >> price;
                cout << "Enter supplier ID:";
                cin >> sup_ID;
                fileo << BatchID << endl;
                fileo << current_cap << endl;
                fileo << NoOfDoses << endl;
                fileo << vacName << endl;
                fileo << BatchID << endl;
                fileo << exp_date << endl;
                fileo << price << endl;
                fileo << sup_ID << endl;
                WR_cap = current_cap;
                fileo.close();
            }
            system("pause");
            menu1();
            cin >> choice;
        }
    }
}

void Admin::search_center() {
    system("cls");
    cout << "\nEnter WareHouse Name:";
    cin.ignore();
    getline(cin, WR_Name);
    fname = "WareHouses\\" + WR_Name + ".txt";
    //cout<<fname;
    string wrcap, nbatch, rcap, ndoses, vacnamae, idbtch, expiry, pofbtch, supplier;
    system("cls");
    cout << "DATA OF WAREHOUSE : " << WR_Name << endl << endl << endl;
    filei.open(fname.c_str());
    while (!filei.eof()) {
        getline(filei, nbatch);
        getline(filei, rcap);
        getline(filei, ndoses);
        getline(filei, vacnamae);
        getline(filei, idbtch);
        getline(filei, expiry);
        getline(filei, pofbtch);
        getline(filei, supplier);
        if (!filei.eof()) {
            //cout << "Remaining Warehouse Capacity : " << wrcap << endl;
            cout << "-------------------------------" << endl;
            cout << "Batch : " << nbatch << endl;
            cout << "Capacity of Warehouses: " << rcap << endl;
            cout << "Doses In Batch : " << ndoses << endl;
            cout << "Vaccine Name : " << vacnamae << endl;
            cout << "Batch ID : " << idbtch << endl;
            cout << "Date Of Expiry : " << expiry << endl;
            cout << "Prize Of The Batch : " << pofbtch << endl;
            cout << "Supplier ID : " << supplier << endl;
        }
    }
}

void SuperAdmin::add_doctor() {
    system("cls");
    cout << "ADD DOCTOR" << endl;
    fstream file;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Identification Number: ";
    cin >> identification_id;
    cout << "Enter Id : ";
    cin >> id;
    if (id.length() != 15)
    {
        cout << "\nInvalid ID Card Number";
        cout << "Enter Id : ";
        cin >> id;
    }
    else
    {
        // The first letter should not start with 0 or 1
        if (id[0] == '0' || id[0] == '1')
        {
            cout << "\nInvalid ID Card Number";
            cout << "Enter Id : ";
            cin >> id;
        }
        else
        {
            cout << "\nValid ID Card Number";
        }
    }
B:
    cout << "\n\n\t\tEnter Your Mobile Number: ";
    cin >> phone_no;
    if (phone_no.length() != 11)
    {
        cout << "\nInvalid Phone Number";
        goto B;
    }
    else
    {
        // The First letter should not start with 0 or 1
        if (phone_no[0] != '0' || phone_no[0] == '1')
        {
            cout << "\nInvalid Phone Number";
            goto B;
        }
        else
        {
            cout << "\nValid Phone Number";
        }
    }
    cout << "\n\n\t\tEnter Age: ";
    cin >> age;
    cout << "\n\n\t\tEnter Center Allotted: ";
    cin >> center;
    string fname;
    fname = id + "\n" + name + "\n" + identification_id + "\n" + phone_no + "\n" + age + "\n" + center + "\n";
    file.open("DoctorData.txt", ios::app);
    file << fname;
    cout << "\n\nYOUR DATA HAS BEEN SUCCESSFULLY INSERTED" << endl;
    cout << "\n\nPress Any Key To Continue..";
    file.close();
}

void SuperAdmin::display_doctor_data() {
    system("cls");
    fstream file;
    string doctor;
    file.open("DoctorData.txt");
    while (!file.eof()) {
        getline(file, doctor);
        cout << doctor << endl;
    }
    file.close();
}

void SuperAdmin::search_doctor_data() {
    string fname;
    bool i = false;
    system("cls");
    cout << "Enter CNIC of Doctor:";
    cin >> search;
    ifstream fin;
    fin.open("DoctorData.txt");
    while (i != true) {
        getline(fin, id);
        getline(fin, name);
        getline(fin, identification_id);
        getline(fin, phone_no);
        getline(fin, age);
        getline(fin, center);
        if (id == search) {
            i = true;
            fname = "ID Card : " + id + "\nName :" + name + "\nIdentification Number : " + identification_id + "\nPhone Number : " + phone_no + "\nAge : " + age + "\nCenter Allotted : " + center + "\n\n";
            cout << fname;
        }
    }
    fin.close();
}

void user::add_patient_data() {
    ofstream fileo;
    fileo.open("UserData.txt", ios::app);
    cout << "Enter youUr ID card number:";
    cin >> id;
    cin.ignore();
    cout << "Enter your name:";
    getline(cin, name);
    cout << "Enter your address:";
    getline(cin, address);
    cout << "Enter your age:";
    cin >> age;
    cout << "Enter tour Phone number:";
    cin >> phone_no;

    fileo << username << endl;
    fileo << password << endl;
    fileo << id << endl;
    fileo << name << endl;
    fileo << age << endl;
    fileo << address << endl;
    fileo << phone_no << endl;
    fileo.close();
}

void covid_management::patient_show_data() {
    string fname;
    bool i = false;
    system("cls");
    cout << "Enter CNIC of Pateint:";
    cin >> search;
    ifstream fin;
    fin.open("UserData.txt");
    while (i != true) {
        getline(fin, username);
        getline(fin, password);
        getline(fin, id);
        getline(fin, name);
        getline(fin, phone_no);
        getline(fin, age);
        getline(fin, address);
        if (id == search) {
            i = true;
            fname = "ID Card : " + id + "\nName :" + name + "\nPhone Number : " + phone_no + "\nAge : " + age + "\n\n";
            cout << fname;
        }
    }
    fin.close();
}
