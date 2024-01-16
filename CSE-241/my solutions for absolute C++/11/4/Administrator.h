#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <string>
using namespace std;

class Administrator{

public: 
    Administrator();
    Administrator(string newName, string newPassword);
    bool Login();
private:
    string name;
    string password;
};

#endif