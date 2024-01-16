#include <iostream>
#include "Security.h"
#include "User.h"

using namespace std;

User::User(): 
    name("nullName"), password("nullPassword"){/*empty*/}
User::User(string newName, string newPassword):
    name(newName), password(newPassword){/*empty*/}

bool User::Login(){
    return( Security::validate(name, password) == 2 ||
            Security::validate(name, password) == 1);
}