#include <iostream>
#include <string>
#include "User.h"
#include "Administrator.h"

using namespace std;

int main(){
    User wrongUser("wrongUserName", "wrongUserPassword");
    User newUser("abbott", "monday");
    Administrator wrongAdmin("wrongAdminName", "wrongAdminPassword");
    Administrator newAdmin("costello", "tuesday");

    cout << wrongUser.Login() << endl;
    cout << newUser.Login() << endl;
    cout << wrongAdmin.Login() << endl;
    cout << newAdmin.Login() << endl;

    return 0;
}