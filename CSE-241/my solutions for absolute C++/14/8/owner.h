#ifndef OWNER_H
#define OWNER_H

#include "viewer.h"
#include <iostream>
#include <string>

using std::string;

namespace KurutBlog{

    class Owner: public Viewer{
    public:
        Owner(string theName, Blog *theBlog);
        Owner(Blog *theBlog);

        void displayMenu() const;
        void blogOption(char command); 
        
    };
}

#endif