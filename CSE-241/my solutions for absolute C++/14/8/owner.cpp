#include <iostream>
#include <string>
#include "owner.h"

using std::cout;
using std::cin;
using std::endl;

namespace KurutBlog{
    Owner::Owner(string theName, Blog *theBlog): Viewer(theName, theBlog){/**/}

    Owner::Owner(Blog *theBlog): Viewer(theBlog){/**/}

    void Owner::displayMenu() const{
        cout << "Hello owner " << getName() << endl 
            << "Enter 'a' to post a new message,\n"
            << "Enter 'b' to display messages,\n"
            << "Enter 'c' to delete a message\n>";
    }

    void Owner::blogOption(char command){
        if(command == 'a'){
            Message newMessage;
            string content;
            int newMessageId;
            for(newMessageId = 0; newMessageId < MAX_POST; ++newMessageId)
                if(!getBlog()->isThereMessage(newMessageId))
                    break;

            if(newMessageId == MAX_POST)
                cout << "Maximum number of posts exceeded!\n";
            else{
                cout << "Enter message content: ";
                cin.get();
                getline(cin, content);;
                newMessage.setContent(content);
                newMessage.setId(newMessageId);
                getBlog()->addPost(newMessage);
            }
        }
        else if(command == 'b')
            displayContents();
        else if(command == 'c'){
            int toDelete;
            displayContents();
            cout << "Enter the index of the message you want to delete\n>";
            cin >> toDelete;
            getBlog()->deletePost(toDelete);
        }

    }
}