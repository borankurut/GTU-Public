package homework1;

import java.io.PrintStream;

public class TestClass4{
    public static void main(String[] args) {

        try{
            PrintStream fileStream = new PrintStream("LDLinkedListTestClass4Output.txt");
            System.setOut(fileStream);
        }
        catch(Exception e){
            System.out.println(e);
        }

        long startTime = System.currentTimeMillis();

        int postId = 0;
        int messageId = 0;
        int commentId = 0;
        int likeId = 0;

        LDLinkedList<Account> accounts = new LDLinkedList<Account>();

        /*
         * •    Show their own action history.
         *  For instance, assume that gizemsungu logged and did some actions. 
         *  When she wants to see her history, 
         *  your program provides to show the following list related
         *  to her actions: o You liked sibelgulmez’s post id: 2 
         * 
         * o You followed sibelgulmez 
         * o You followed gokhankaya 
         * o You unfollowed sibelgulmez 
         * o You commented gokhankaya’s post id:3
         * o You followed sibelgulmez
         */
         
        // created 10 accounts, each of them is logged in and they share a post.
        System.out.println("created 10 accounts, each of them is logged in and they share a post.");
        for(int i = 0; i < 10; ++i){
            String accountUsername = "account" + i;
            accounts.add(new Account(i, accountUsername, 10, 10, 2000, "Istanbul"));
            accounts.get(i).login(accountUsername);
            accounts.get(i).addPost(postId++, "1. post of " + i);
        }
        System.out.println();


        // all other 9 accounts follows account0.
        System.out.println("To show the list of followers of Account0,"
            + "Account0 is followed by other 9 accounts:");
        for(int i = 1; i < 10; ++i){
            accounts.get(i).follow(accounts.get(0));
            accounts.get(0).viewProfile(accounts.get(0));
        }

        // all other 9 accounts unfollows account0.
        System.out.println("To show the list of followers of Account0,"
            + "Account0 is unfollowed by other 9 accounts:");

        for(int i = 1; i < 10; ++i){
            System.out.println(String.format("%s unfollows account0", accounts.get(i).getUsername()));
            accounts.get(i).unfollow(accounts.get(0));
            System.out.println("(account0's followers list (deleted nodes included):");
            accounts.get(0).getFollowers().printAllNodes();
            System.out.println();
        }

        //  for all accounts until last one, 
        //  follow, unfollow next account and like, comment, unlike, uncomment their post.

        for(int i = 0; i < accounts.size() - 1; ++i){
            
            // account i likes account i+1's post.
            accounts.get(i).like(likeId++, accounts.get(i+1).getPosts().get(0));
            // accounti comments accounti+1's post.
            accounts.get(i).comment(commentId++, 
                accounts.get(i+1).getPosts().get(0), "some comment");
            
            System.out.println("after like and comment");
            accounts.get(i+1).viewPostsInteractions(accounts.get(i+1));

            // account i unlikes and deletes his comment from accounti+1's post.
            accounts.get(i).unLike(accounts.get(i+1).getPosts().get(0));
            accounts.get(i).unComment(accounts.get(i+1).getPosts().get(0).getComments().get(0), 
                accounts.get(i+1).getPosts().get(0));

            System.out.println("after unlike and delete comment.");
            accounts.get(i+1).viewPostsInteractions(accounts.get(i+1));

            // account i follows accounti+1.
            accounts.get(i).follow(accounts.get(i+1));
            System.out.println("After account" + i + " follows account"+ (i+1) + ".");
            accounts.get(i).viewProfile(accounts.get(i));
            accounts.get(i).viewProfile(accounts.get(i+1));

            // account i unfollows accounti+1.
            accounts.get(i).unfollow(accounts.get(i+1));
            System.out.println("After account" +i +" unfollows account " + (i+1) + ".");
            accounts.get(i).viewProfile(accounts.get(i));   
            accounts.get(i).viewProfile(accounts.get(i+1));

            // accounti blocks accounti+1

            accounts.get(i).block(accounts.get(i+1));
            System.out.println("After blocking account" + (i+1) + ":");
            System.out.println("account" + i + " is blocked: " + accounts.get(i).getBlocked());
            System.out.println();

            // accounti unblocks accounti+1

            accounts.get(i).unblock(accounts.get(i+1));
            System.out.println("After unblocking account" + (i+1) + ":");
            System.out.println("account" + i + " is blocked: " + accounts.get(i).getBlocked());
            System.out.println();


            // show history of accounti
            System.out.println("account" + i + " History:");

            accounts.get(i).viewHistory();
        }

        long endTime = System.currentTimeMillis();
        long elapsedTime = endTime - startTime;
        System.out.println("Elapsed time in milliseconds: " + elapsedTime);
    }   
}

