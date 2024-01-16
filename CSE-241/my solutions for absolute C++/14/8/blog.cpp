#include <iostream>
#include "blog.h"

using namespace std;

namespace KurutBlog{

    void Blog::addPost(Message newMessage){
        if(!isThereMessage(newMessage.getId()))
            posts.push_back(newMessage);
        else{
            cerr << "Attempt to add 2 posts with same id!\n";
            exit(1);
        }
    }

    void Blog::deletePost(int messageId){
        int i;
        for(i = 0; i < posts.size(); ++i)
            if(messageId == posts[i].getId())
                posts.erase(posts.begin() + i);
    }

    void Blog::deletePost(Message message){
        int messageId = message.getId();
        deletePost(messageId);
    }

    const vector<Message>& Blog::getPosts() const{
        return posts;
    }

    bool Blog::isThereMessage(int id) const{
        bool found = false;
        int i;
        for(i = 0; i < MAX_POST && i < posts.size(); ++i)
            if(posts.operator[](i).getId() == id)
                found = true;
        return found;
    }
}