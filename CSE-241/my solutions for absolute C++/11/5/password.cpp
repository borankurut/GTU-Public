#include <iostream>
#include <string>
#include <ctype.h>
#include "password.h"

using namespace std;

namespace{
    string password;
    bool isValid(){
        bool valid = 1;
        if(password.length() < 8)
            valid = 0;
        if(valid){
            valid = 0;
            int i;
            for(i = 0; i < password.length(); ++i)
                if(isalpha(password[i]) == 0)
                    valid = 1;
        }
        return(valid);
    }
}
namespace Authenticate{
    void inputPassword(){
        do{
            cout << "Enter your password (at least 8 characters " <<
                    "and at least one non-letter" << endl;
            cin >> password;
        }while(!isValid());
    }
    string getPassword(){
        return password;
    }
}