package homework1;

import java.util.ArrayList;
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

    private ArrayList<Post> posts;

    private ArrayList<Message> messages;

    private ArrayList<Account> following;
    private ArrayList<Account> followers;
    private ArrayList<Account> blocked;

    private ArrayList<String> actionHistory;

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

        posts = new ArrayList<Post>();
        messages = new ArrayList<Message>();

        following = new ArrayList<Account>();
        followers = new ArrayList<Account>();
        blocked = new ArrayList<Account>();

        actionHistory = new ArrayList<String>();

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

    public ArrayList<Account> getFollowers(){return followers;}
    public ArrayList<Account> getBlocked(){return blocked;}


    /**
     * 
     * @return username of the account.
     */
    public String getUsername(){return username;}


    @Override
    public String toString() {
        return username;
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
        posts.add(new Post(postId, accountId, content));
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
        posts.add(p);
    }

    /**
     * This function run when an account send a message. 
     * For both the sender account and receiver account.
     * @param m message to be added.
     */
    private void addMessage(Message m){
        messages.add(m);
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

        if(a.blocked.contains(this)){
            System.out.println("Failed message: " + a.getUsername() + " is blocked " + username + "\n");
            return;
        }

        if(following.contains(a)){
            Message m = new Message(newMessageId, accountId, a.getId(), content);
            a.addMessage(m);
            this.addMessage(m);
            actionHistory.add(String.format("You messaged to %s", a.getUsername()));
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
        for(Like l :p.getLike()){
            if(l.getAccount() == this)
                return;
        }
        Like l = new Like(newLikeId, this, p);
        l.interact(p);
        actionHistory.add(String.format("You liked %s's post id: %s", 
            p.getAccountId(), p.getId()));
    }

    /**
     * Removes like from the post likes.
     * 
     * @param p post that is unliked.
     */
    public void unLike(Post p){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        System.out.println(p.getLike().size());
        for(int i = 0; i < p.getLike().size(); ++i){
            if(p.getLike().get(i).getAccount() == this){
                p.getLike().get(i).unInteract(p);
                actionHistory.add(String.format("You unliked %s's post id: %s", 
                    p.getAccountId(), p.getId()));
            }
        }
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
        actionHistory.add(String.format("You commented %s's post id: %s", p.getAccountId(), p.getId()));
    }

    /**
     * 
     * @param com   comment that is going to be deleted.
     * @param p     post that is commented.
     */
    public void unComment(Comment com, Post p){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }
        com.unInteract(p);
        actionHistory.add(String.format("You deleted your comment of %s's post id: %s", 
            p.getAccountId(), p.getId()));
    }

    /**
     * 
     * @return posts array of the accounts.
     */
    public ArrayList<Post> getPosts(){
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

        if(!a.followers.contains(this) && !this.following.contains(a)){
            a.followers.add(this);
            this.following.add(a);
            actionHistory.add(String.format("You followed %s", a.getUsername()));
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
        // blocked unfollow won't be shown in action history
        a.actionHistory.remove(a.actionHistory.size() - 1);
        this.unfollow(a);
        // blocked unfollow won't be shown in action history
        this.actionHistory.remove(this.actionHistory.size() - 1);

        blocked.add(a);
        actionHistory.add(String.format("You blocked %s", a.getUsername()));
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

        if(!blocked.contains(a))
            return;

        blocked.remove(a);
        actionHistory.add(String.format("You unblocked %s", a.getUsername()));
    }

    /**
     * Removes account a from the following array and 
     * removes this account from the followers array of account a.
     * @param a account that is unfollowed.
     */
    public void unfollow(Account a){
        if(a == this)
            return;

        if(!(this.following.contains(a) && a.followers.contains(this)))
            return;

        this.following.remove(a);
        a.followers.remove(this);
        actionHistory.add(String.format("You unfollowed %s", a.getUsername()));
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
        for (Message m : messages) {
            if(m.getSenderId() == accountId)
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
        for (Message m : messages) {
            if(m.getReceiverId() == accountId)
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

        if(a.blocked.contains(this)){
            System.out.println("Failed view: " + a.getUsername() + " is blocked " + username + "\n");
            return;
        }

        String result = String.format(
            "--------------------\n"+
            "User ID: %s\n"         +
            "Username: %s\n"        +
            "Location: %s\n"        +
            "Birth Date: %s\n"      +
            "%s is following %s account(s) and has %s follower(s)\n",
            a.accountId, a.username, a.location, a.getBirthDateFormat(), 
            a.username, a.following.size(), a.followers.size());
        if(a.followers.size() > 0){
            result += String.format("The followers of %s are: ", a.username);
                for(int i = 0; i < a.followers.size(); ++i){
                    result += a.followers.get(i).username + ", ";
                }
            result += "\n";
        }

        if(a.following.size() > 0){
            result += String.format("%s is following: ", a.username);
            for(int i = 0; i < a.following.size(); ++i){
                result += a.following.get(i).username + ", ";
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

        if(a.blocked.contains(this))
            return;


        String result = "";
        for(int i = 0; i < a.posts.size(); ++i){
            result += "(Post Id: " + a.getPosts().get(i).getId() + ") " + a.username + ": "
            + a.getPosts().get(i).getContent() + "\n"; 
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

        for(int i = 0; i < a.posts.size(); ++i){
            System.out.println(String.format("(PostID: %s): %s", 
                a.posts.get(i).getId(), a.posts.get(i).getContent()));
            if(a.posts.get(i).getLikeCount() == 0)
                System.out.println("The post has no likes.");
            else{
                System.out.print("The post was liked by the following account(s): ");
                for(int j = 0; j < a.posts.get(i).getLikeCount(); ++j){
                    System.out.print(a.posts.get(i).getLike().get(j).interactedAccount.username);
                    System.out.print(", ");
                }
                System.out.println();
            }

            if(a.posts.get(i).getCommentCount() == 0){
                System.out.println("The post has no comments.");
            }
            else{
                System.out.println("The post has " + a.posts.get(i).getCommentCount() + " comment(s)...");
                for(int j = 0; j < a.posts.get(i).getCommentCount(); ++j){
                    System.out.println(a.posts.get(i).getComments().get(i));
                }
            }
            System.out.println("----------------------------");
        }
    }

    /**
     * Prints the inbox of the account by filtering the messages array by receiver id is this account.
     */
    public void printInbox(){
        for(int i = 0; i < messages.size(); ++i){
            if(messages.get(i).getReceiverId() == accountId){
                System.out.print(messages.get(i));
            }
        }
    }
    
    /**
     * Prints the outbox of the account by filtering the messages array by sender id is this account.
     */
    public void printOutbox(){
        for(int i = 0; i < messages.size(); ++i){
            if(messages.get(i).getSenderId() == accountId){
                System.out.print(messages.get(i));
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
        for(int i = 0; i < messages.size(); ++i){
            if(messages.get(i).getReceiverId() == accountId){
                System.out.println(String.format(
                    "----------------\n"+
                    "Message Id: %s\n"  + 
                    "From: %s\n"        +
                    "To: %s\n"          +
                    "Message: %s\n",messages.get(i).getId(),
                    idToUsername(messages.get(i).getSenderId()),
                    username,
                    messages.get(i).getContent()
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
        for(int i = 0; i < messages.size(); ++i){
            if(messages.get(i).getSenderId() == accountId){
                System.out.println(String.format(
                    "Message Id: %s\n"  + 
                    "From: %s\n"        +
                    "To: %s\n"          +
                    "Message: %s\n",messages.get(i).getId(),
                    username,
                    idToUsername(messages.get(i).getReceiverId()),
                    messages.get(i).getContent()
                ));
            }
        }
    }

    public void viewHistory(){
        if(!isLoggedIn()){
            System.err.println("User is not logged in!");
            return;
        }

        for(int i = 0; i < actionHistory.size(); ++i){
            System.out.println(actionHistory.get(i));
        }
        System.out.println();
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
        for(int i = 0; i < following.size(); ++i){
            if(following.get(i).accountId == id)
                return following.get(i).username;
        }
        for(int i = 0; i < followers.size(); ++i){
            if(followers.get(i).accountId == id)
                return followers.get(i).username;
        }

        for(int i = 0; i < blocked.size(); ++i){
            if(blocked.get(i).accountId == id)
                return blocked.get(i).username;
        }
        return "Not Found";
    }
}