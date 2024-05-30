#pragma once
#include <iostream>
#include <cstring>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;
class covid_management
{
protected:
    string username, password, usn, psd, name, search, age, id, phone_no, profession, address, vaccine_name;
    int tm, add, center_no, c, dose;
public:
    void patient_show_data();   // 3
};

class user :public covid_management
{
protected:
    covid_management cv;
    fstream file;
    int choice = 0;
    bool b = false;
public:
    void usersmenu();
    void add_patient_data();    // 2
    void User();
    void Register();
    void login();
    void applyfirst(string);
    void applysecond(string);

};

class SuperAdmin :public covid_management
{
private:
    char SPName[20];
    char SPPass[20];
    int ch, i, gen_captcha, Input_captcha;
    int super_admin_choice;
    string identification_id, center;
public:
    bool SuperAdmin_login();
    void super_admin();
    void super_admin_menu();
    void add_doctor();            // 6
    void search_doctor_data();    // 7
    void display_doctor_data();   // 8
    void applied_first_vaccine();
    void applied_second_vaccine();

};


class Doctor :public user {
private:
    int L_bloodP, H_bloodP, O_level, CHO_level;

public:
    void vitals();


};


class Admin :public covid_management
{
private:
    Doctor d;
    user usrr;
    SuperAdmin sa;
    int WR_cap = 20000, j = 0, current_cap = 0, BatchID = 100;
    string WR_Name = "\0", WR_Address = "\0", fname = "\0", exp_date = "\0", vactyp, vacName, vacID, center1 = "Karachi", center2 = "Lahore", center3 = "Faislabad";
    ofstream fileo;
    ifstream filei;
    int NoOfDoses = 0, price = 0, choice = 0, sup_ID = 0, sum_vaccine_c1 = 0, sum_vaccine_c2 = 0, sum_vaccine_c3 = 0;
public:
    void menu1();
    void menu();
    void admin();
    void admin_menu();
    void add_vaccine_stock();     // 1
    void search_center();       // 1
};