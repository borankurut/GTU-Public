#ifndef BLOG_H
#define BLOG_H

#include <vector>
#include "message.h"

using std::vector;

namespace KurutBlog{
    class Blog{

    public:
        void addPost(Message newMessage);
        void deletePost(int messageId);
        void deletePost(Message message);
        bool isThereMessage(int id) const;

        const vector<Message>& getPosts() const;
    private:
        vector<Message> posts;

    };

    const int MAX_POST = 10000;
}

#endif