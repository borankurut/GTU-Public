#include <iostream>
#include "message.h"
#include "blog.h"
#include "viewer.h"
#include "owner.h"

using namespace std;
using namespace KurutBlog;

void test();

int main(){
    char ans = 'y';
    while(ans == 'y' || ans == 'Y'){
        test();
        cout << "newTest? \n";
        cin >> ans;
    }

    return(0);
}

void test(){
    Blog newBlog;
    Viewer myGuy("myGuy", &newBlog);
    Owner boran("Boran", &newBlog);

    char command;
    do{
        cout << "enter x to end the owner test\n";
        boran.displayMenu();
        cin >> command;
        boran.blogOption(command);
    }while(command != 'x');

    do{
        cout << "enter x to end the viewer test\n";
        myGuy.displayMenu();
        cin >> command;
        myGuy.blogOption(command);
    }while(command != 'x');
}