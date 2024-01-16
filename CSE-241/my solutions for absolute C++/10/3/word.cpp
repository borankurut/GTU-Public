#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char str[1000];
    cin.getline(str, 1000, '\n');
    
    char *head = str;
    char *tail = &str[strlen(str) - 1];

    int fromHead = 1,
        fromTail = 1;

    while(head != &str[strlen(str) - 1] && tail != str){
        if(*head == ' ')
            ++fromHead;
        if(*tail == ' ')
            ++fromTail;
        ++head;
        --tail;
    }

    cout << "From head: " << fromHead << endl;
    cout << "From tail: " << fromTail << endl;

    return(0);
}