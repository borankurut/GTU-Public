#include <iostream>
#include <string>
#include "user.h"

using namespace std;

namespace{
    string username;
    bool isValid(){
        return (username.size() == 8);
    }
}

namespace Authenticate{
    void inputUserName(){
        do{
            cout << "Enter your username (8 letters only)\n>";
            cin >> username;
        }while(!isValid());
    }

    string getUserName(){
        return username;
    }
}