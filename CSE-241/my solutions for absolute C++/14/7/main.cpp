#include <iostream>
#include "document.h"
#include "email.h"
#include "file.h"

using namespace std;
using namespace KurutDocument;


int main(){
    Email newEmail("someText", "someSender", "someRecipient", "someTitle");
    Email testCopyCon(newEmail);
    Email testAssign;
    testAssign = newEmail;

    newEmail.setSender("hehehe");
    newEmail.setText("hahaha");

    newEmail.debugPrint();
    testAssign.debugPrint();

    cout << "\nEmail test ended\n\n";

    File newFile("SomeText", "SomePathName");
    File testCopyFile(newFile);
    File testAssignFile;
    testAssignFile = newFile;

    newFile.setText("newhahatext");
    newFile.setPathName("newhahapath");

    cout << "newfile: " << newFile.getText() << "  " << newFile.getPathName() << endl;
    cout << "testcopy: " << testCopyFile.getText() << "  " << testCopyFile.getPathName() << endl;
    cout << "testAssign: " << testAssignFile.getText() << "  " << testAssignFile.getPathName() << endl;

    cout << "ContainsTest:\n";
    Email contain("this text contains c++ word", "Sender", "Recipient", "Title");
    Email containnt("this text does not contain forbidden word", "Sender", "Recipient", "Title");

    cout << "contain: " << ContainsKeyword(contain, "c++") << endl;
    cout << "containnt: " << ContainsKeyword(containnt, "c++") << endl;

    return(0);
}