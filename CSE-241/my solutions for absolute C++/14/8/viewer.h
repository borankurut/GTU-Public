#ifndef VIEWER_H
#define VIEWER_H

#include <vector>
#include "blog.h"

using std::vector;

namespace KurutBlog{
    class Viewer{
        
    public:
        Viewer(string theName, Blog *theBlog);
        Viewer(Blog *theBlog);

        void displayMenu() const;
        void displayContents() const;
        void blogOption(char command) const; // const because viewer.
        string getName() const;
        Blog* getBlog() const;

    private:
        Blog *blog;
        string name;
    };
}

#endif