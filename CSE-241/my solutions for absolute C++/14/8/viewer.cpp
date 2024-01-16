#include "viewer.h"
#include "blog.h"
#include <iostream>

using std::cout;
using std::endl;


namespace KurutBlog{

    Viewer::Viewer(Blog *theBlog): name(""), blog(theBlog){/**/}

    Viewer::Viewer(string theName, Blog *theBlog):
        name(theName), blog(theBlog){/**/}

    void Viewer::displayContents() const{
        int ix;
        for(ix = 0; ix < blog->getPosts().size(); ++ix)
            cout << blog->getPosts().operator[](ix).getId() << ": " 
            << blog->getPosts().operator[](ix) << endl;
    }

    void Viewer::displayMenu() const{
        cout << "Hello viewer " << name << endl 
            << "Enter 'b' to display messages\n>";
    }

    void Viewer::blogOption(char command) const{
        if(command == 'a' || command == 'c')
            cout << "You don't have permission to do that";
        if(command == 'b')  
            displayContents();
    }

    string Viewer::getName() const {return name;}

    Blog* Viewer::getBlog() const {return blog;}
}