#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User{

public: 
    User();
    User(string newName, string newPassword);
    bool Login();
private:
    string name;
    string password;
};

#endif