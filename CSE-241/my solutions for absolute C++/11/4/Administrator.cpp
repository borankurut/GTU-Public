#include <iostream>
#include "Security.h"
#include "Administrator.h"


using namespace std;

Administrator::Administrator(): 
    name("nullName"), password("nullPassword"){/*empty*/}
Administrator::Administrator(string newName, string newPassword):
    name(newName), password(newPassword){/*empty*/}

bool Administrator::Login(){
    return(Security::validate(name, password) == 2);
}