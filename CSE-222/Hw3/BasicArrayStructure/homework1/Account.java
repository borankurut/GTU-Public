package homework1;

/**
 * Account class contains each users information that are username, birthdate, location, posts, messages,
 * followed accounts, following accounts, blocked accounts and whether the user is logged in or not.
 */

public class Account{

    private final int accountId;

    private String username;

    private int birthDay;
    private int birthMonth;
    private int birthYear;

    private String location;

    private Post posts[];
    private int postsSize;

    private Message messages[];
    private int messagesSize;

    private Account following[];
    private int followingSize;
    private Account followers[];
    private int followersSize;
    private Account blocked[];
    private int blockedSize;

    private boolean loggedIn;

    /**
     * Constructor of the Account object.
     * @param newId             id of the user.
     * @param newUsername       username of the user.
     * @param newBirthDay       users birthday day.
     * @param newBirthMonth     users birthday month.
     * @param newBirthYear      users birthday year.
     * @param newLocation       location of the user, ex: "Istanbul".
     */
    public Account(int newId, String newUsername, int newBirthDay, int newBirthMonth, 
        int newBirthYear, String newLocation){

        accountId = newId;
        username = newUsername;

        birthDay = newBirthDay;
        birthMonth = newBirthMonth;
        birthYear = newBirthYear;

        location = newLocation;

        posts = new Post[10];
        postsSize = 0;
        messages = new Message[10];
        messagesSize = 0;

        following = new Account[10];
        followingSize = 0;
        followers = new Account[10];
        followersSize = 0;
        blocked = new Account[10];
        blockedSize = 0;

        loggedIn = false;

        System.out.println(String.format("An account with username %s has been created.",
        username));
    }

    /**
     * 
     * @return  whether user is loggedin.
     */
    private boolean isLoggedIn(){
        return loggedIn;
    }

    /**
     * Sets loggedIn to true if the usernameInput is correct.
     * @param usernameInput  username of the account
     */
    public Account login(String usernameInput){
        if (username == usernameInput){
            loggedIn = true;
            return this;
        }
        else
            return null;
    }

    /**
     * Sets loggedIn false.
     */
    public void logout(){
        loggedIn = false;
    }

    /**
     * 
     * @return id of the account.
     */
    public int getId(){
        return accountId;
    }


    /**
     * 
     * @return username of the account.
     */
    public String getUsername(){return username;}


    @Override
    public String toString() {
        return String.format("Account: \nid: %s\nusername: %s\nbirthDate: %s/%s/%s \nlocation: %s\n"
        +"posts: %s\nmessages:%s",
        accountId, username, birthDay, birthMonth, birthYear, location, posts, messages);
    }

    /**
     * Creates post for the account.
     * 
     * @param postId    id of the post to be created.
     * @param content   content of the post
     */
    public void addPost(int postId, String content){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        posts[postsSize++] = (new Post(postId, accountId, content));
    }

    /**
     * addPost method to add an already created post.
     * 
     * @param p post to add.
     */
    public void addPost(Post p){
        if(p.getAccountId() != accountId){
            System.err.println(String.format(
                "This post(%s) don't belong to this account(%s).", p.getId(), accountId));
            return;
        }
        posts[postsSize++] = p;
    }

    /**
     * This function run when an account send a message. 
     * For both the sender account and receiver account.
     * @param m message to be added.
     */
    private void addMessage(Message m){
        messages[messagesSize++] = m;
    }

    /**
     * Adds the message object to both sender and receiver.
     * @param a         receiver account
     * @param content   message content
     */
    public void sendMessage(int newMessageId, Account a, String content){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }

        if(this == a)
            return;

        for(int i = 0; i < a.blockedSize; ++i){
            if(a.blocked[i] == this){
                System.out.println("Failed message: " + a.getUsername() + " is blocked " + username + "\n");
                return;
            }
        }

        boolean followingContains = false;

        for(int i = 0; i < followingSize; ++i){
            if(following[i] == a)
                followingContains = true;
        }

        if(followingContains){
            Message m = new Message(newMessageId, accountId, a.getId(), content);
            a.addMessage(m);
            this.addMessage(m);
        }
    }

    /**
     * Adds like object in the post that is liked.
     * 
     * @param newLikeId     id of the like object.
     * @param p             post that is liked by account.
     */
    public void like(int newLikeId, Post p){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        Like l = new Like(newLikeId, this, p);
        l.interact(p);
    }

    /**
     * Adds comment object in the post that is commented.
     * 
     * @param newCommentId  if of the comment object.
     * @param p             post that is commented.
     * @param content       content of the comment
     */
    public void comment(int newCommentId, Post p, String content){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        Comment c = new Comment(newCommentId, this, p, content);
        c.interact(p);
    }

    /**
     * 
     * @return posts array of the accounts.
     */
    public Post[] getPosts(){
        return posts;
    }


    /**
     * Adds a in the following array.
     * and adds this account to the followers array of the followed account.
     * 
     * @param a followed account.
     */
    public void follow(Account a){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        if(a == this)
            return;

        boolean aFollowersContainsThis = false;
        boolean thisFollowingContainsA = false;

        for(int i = 0; i < a.followersSize; ++i){
            if(a.followers[i] == this)
                aFollowersContainsThis = true;
        }

        for(int i = 0; i < this.followingSize; ++i){
            if(this.following[i] == a)
                thisFollowingContainsA = true;
        }

        if(!aFollowersContainsThis && !thisFollowingContainsA){
            a.followers[a.followersSize++] = this;
            this.following[this.followingSize++] = a;
        }
    }   

    /**
     * calls unfollow for each of account with parameter of the other and
     * adds a to the blocked array of this account.
     * 
     * @param a account that is blocked.
     */
    public void block(Account a){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        if(a == this)
            return;
        a.unfollow(this);
        this.unfollow(a);
        blocked[blockedSize++] = a;
    }

    /**
     * Removes account a from the blocked array of this account.
     * 
     * @param a account that is unblocked.
     */
    public void unblock(Account a){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        if(a == this)
            return;

        boolean contains = false;
        for(int i = 0; i < blockedSize; ++i){
            if(blocked[i] == a)
                contains = true;
        }

        if(!contains)
            return;

        Account newBlocked[] = new Account[blockedSize - 1];
        for(int i = 0, k = 0; i < blockedSize; ++i){
            if(blocked[i] != a){
                newBlocked[k] = blocked[i];
                k++;
            }
        }
        blocked = newBlocked;
        blockedSize--;
    }

    /**
     * Removes account a from the following array and 
     * removes this account from the followers array of account a.
     * @param a account that is unfollowed.
     */
    public void unfollow(Account a){
        if(a == this)
            return;

        boolean thisFollowingContainsA = false;
        boolean aFollowersContainsThis = false;

        for(int i = 0; i < this.followingSize; ++i)
            if(this.following[i] == a)
                thisFollowingContainsA = true;
        for(int i = 0; i < a.followersSize; ++i){
            if(a.followers[i] == this)
                aFollowersContainsThis = true;
        }

        if(!(thisFollowingContainsA && aFollowersContainsThis))
            return;

        Account newThisFollowing[] = new Account[this.followingSize - 1];
        Account newAFollowers[] = new Account[a.followersSize - 1];

        for(int i = 0, k = 0; i < this.followingSize; ++i){
            if(this.following[i] != a){
                newThisFollowing[k] = this.following[i];
                k++;
            }
        }

        for(int i = 0, k = 0; i < a.followersSize; ++i){
            if(a.followers[i] != this){
                newAFollowers[k] = a.followers[i];
                k++;
            }
        }

        this.followingSize--;
        a.followersSize--;

        this.following = newThisFollowing;
        a.followers = newAFollowers;
    }


    /**
     * prints outbox message amount.
     */
    public void checkOutbox(){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        
        int outboxCounter = 0;
        for(int i = 0; i < messagesSize; ++i){
            if(messages[i].getSenderId() == accountId)
                outboxCounter++;
        }

        System.out.println(String.format(
            "There is/are %s message(s) in the outbox.", outboxCounter));
    }


    /**
     * prints inbox message amount.
     */
    public void checkInbox(){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        
        int inboxCounter = 0;
        for(int i = 0; i < messagesSize; ++i){
            if(messages[i].getReceiverId() == accountId)
                inboxCounter++;
        }

        System.out.println(String.format(
            "There is/are %s message(s) in the inbox.", inboxCounter));
    }


    /**
     * profile of Account a is viewed by this.
     * 
     * @param a Account to view profile of.
     */
    public void viewProfile(Account a){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }

        for(int i = 0; i < a.blockedSize; ++i){
            if(a.blocked[i] == this){
                System.out.println("Failed view: " + a.getUsername() + " is blocked " + username + "\n");
                return;
            }
        }

        String result = String.format(
            "--------------------\n"+
            "User ID: %s\n"         +
            "Username: %s\n"        +
            "Location: %s\n"        +
            "Birth Date: %s\n"      +
            "%s is following %s account(s) and has %s follower(s)\n",
            a.accountId, a.username, a.location, a.getBirthDateFormat(), 
            a.username, a.followingSize, a.followersSize);
        if(a.followersSize > 0){
            result += String.format("The followers of %s are: ", a.username);
                for(int i = 0; i < a.followersSize; ++i){
                    result += a.followers[i].username + ", ";
                }
            result += "\n";
        }

        if(a.followingSize > 0){
            result += String.format("%s is following: ", a.username);
            for(int i = 0; i < a.followingSize; ++i){
                result += a.following[i].username + ", ";
            }
        }

        // read incoming messages if account is on his/her profile.
        if(a == this)
            viewInbox();

        System.out.println(result);
    }

    /**
     * Formats birthdate data and returns the formatted string
     * 
     * @return formatted birthdate to use in profileView.
     */
    private String getBirthDateFormat(){
        String day;
        String month;
        String year;
        if(birthDay < 10)
            day = "0" + String.format("%s",birthDay);
        else
            day = String.format("%s", birthDay);
        if(birthMonth < 10)
            month = "0" + String.format("%s", birthMonth);
        else    
            month = String.format("%s", birthMonth);
        year = String.format("%s", birthYear);

        return String.format("%s.%s.%s", day, month, year);
    }

    /**
     * Shows the posts of the account a if this account is logged in and is not blocked by a.
     * 
     * @param a     Account whose posts will be viewed.
     */
    public void viewPosts(Account a){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        boolean aBlockedContainsThis = false;

        for(int i = 0; i < a.blockedSize; ++i){
            if(a.blocked[i] == this)
                aBlockedContainsThis = true;
        }

        if(aBlockedContainsThis)
            return;


        String result = "";
        for(int i = 0; i < a.postsSize; ++i){
            result += "(Post Id: " + a.getPosts()[i].getId() + ") " + a.username + ": "
            + a.getPosts()[i].getContent() + "\n"; 
        }
        System.out.println(result);
    }

    /**
     *  views interactions of the posts' of account a.
     * 
     * @param a the account whose posts will be viewed
     */
    public void viewPostsInteractions(Account a){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }

        for(int i = 0; i < a.postsSize; ++i){
            System.out.println(String.format("(PostID: %s): %s", 
                a.posts[i].getId(), a.posts[i].getContent()));
            if(a.posts[i].getLikeCount() == 0)
                System.out.println("The post has no likes.");
            else{
                System.out.print("The post was liked by the following account(s): ");
                for(int j = 0; j < a.posts[i].getLikeCount(); ++j){
                    System.out.print(a.posts[i].getLike()[j].interactedAccount.username);
                    System.out.print(", ");
                }
                System.out.println();
            }

            if(a.posts[i].getCommentCount() == 0){
                System.out.println("The post has no comments.");
            }
            else{
                System.out.println("The post has " + a.posts[i].getCommentCount() + " comment(s)...");
                for(int j = 0; j < a.posts[i].getCommentCount(); ++j){
                    System.out.println(a.posts[i].getComments()[i]);
                }
            }
            System.out.println("----------------------------");
        }
    }

    /**
     * Prints the inbox of the account by filtering the messages array by receiver id is this account.
     */
    public void printInbox(){
        for(int i = 0; i < messagesSize; ++i){
            if(messages[i].getReceiverId() == accountId){
                System.out.print(messages[i]);
            }
        }
    }
    
    /**
     * Prints the outbox of the account by filtering the messages array by sender id is this account.
     */
    public void printOutbox(){
        for(int i = 0; i < messagesSize; ++i){
            if(messages[i].getSenderId() == accountId){
                System.out.print(messages[i]);
            }
        }
    }

    /**
     * print inbox of the user if user is loggedin.
     */
    public void viewInbox(){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        for(int i = 0; i < messagesSize; ++i){
            if(messages[i].getReceiverId() == accountId){
                System.out.println(String.format(
                    "----------------\n"+
                    "Message Id: %s\n"  + 
                    "From: %s\n"        +
                    "To: %s\n"          +
                    "Message: %s\n",messages[i].getId(),
                    idToUsername(messages[i].getSenderId()),
                    username,
                    messages[i].getContent()
                ));
            }
        }
    }

    /**
     * print outbox of the user if user is loggedin.
     */
    public void viewOutbox(){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        for(int i = 0; i < messagesSize; ++i){
            if(messages[i].getSenderId() == accountId){
                System.out.println(String.format(
                    "Message Id: %s\n"  + 
                    "From: %s\n"        +
                    "To: %s\n"          +
                    "Message: %s\n",messages[i].getId(),
                    username,
                    idToUsername(messages[i].getReceiverId()),
                    messages[i].getContent()
                ));
            }
        }
    }

    /**
     * This is a function to check all assosiated accounts 
     * with this account to find the username of the user by id. 
     * This function is used to 
     * print the messages of the account properly in viewInbox-viewOutbox functions.
     * because message objects only contain the account id.
     * 
     * @param id    id of the user 
     * @return      username of the user that id is belongs.
     */
    private String idToUsername(int id){
        for(int i = 0; i < followingSize; ++i){
            if(following[i].accountId == id)
                return following[i].username;
        }
        for(int i = 0; i < followersSize; ++i){
            if(followers[i].accountId == id)
                return followers[i].username;
        }

        for(int i = 0; i < blockedSize; ++i){
            if(blocked[i].accountId == id)
                return blocked[i].username;
        }
        return "Not Found";
    }
}