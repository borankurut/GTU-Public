package homework1;

import java.io.PrintStream;

/**
 * Class to test scenario 1.
 */

public class TestClass1{
    public static void main(String[] args) {

        try {
            PrintStream fileStream = new PrintStream("BasicArrayTestClass1Output.txt");
            System.setOut(fileStream);
        } catch (Exception e) {
            System.out.println(e);
        }
        
        long startTime = System.currentTimeMillis();
        
        int accountId = 0;
        int postId = 1;
        int messageId = 0;
        int commentId = 0;
        int likeId = 0;

        Account loggedIn = null;

        System.out.println("\nStep 1... Creating accounts...");
        Account gokhankaya = new Account(accountId++, "gokhankaya", 12, 10, 1990, "Istanbul");
        Account gizemsungu = new Account(accountId++, "gizemsungu", 11, 3, 1995, "Istanbul");
        Account sibelgulmez = new Account(accountId++, "sibelgulmez", 10, 3, 1995, "Istanbul");


        System.out.println("\nStep 2... Logging into an account (username: sibelgulmez)...");
        loggedIn = sibelgulmez.login("sibelgulmez");

        System.out.println("\nStep 3... Sharing two posts...");
        loggedIn.addPost(postId++, "I like Java.");
        loggedIn.addPost(postId++, "Java the coffee...");

        System.out.println("\nStep 4... Following gizemsungu and gokhankaya...");
        loggedIn.follow(gizemsungu);
        loggedIn.follow(gokhankaya);

        System.out.println("\nStep 5... Logging out from account 'sibelgulmez'...");
        loggedIn.logout();

        System.out.println("\nStep 6... Logging into another account (username: gokhankaya)...");
        loggedIn = gokhankaya.login("gokhankaya");

        System.out.println("\nStep 7... Viewing sibelgulmez's profile...");
        loggedIn.viewProfile(sibelgulmez);

        System.out.println("\nStep 8... Viewing sibelgulmez'posts...");
        loggedIn.viewPosts(sibelgulmez);

        System.out.println("\nStep 9... Liking a post of sibelgulmez...");
        loggedIn.like(likeId++, sibelgulmez.getPosts()[0]);

        System.out.println("\nStep 10... Adding a comment on a post of sibelgulmez...");
        loggedIn.comment(commentId, sibelgulmez.getPosts()[0], "me too!");

        System.out.println("\nStep 11... Following sibelgulmez and gizemsungu...");
        loggedIn.follow(sibelgulmez);
        loggedIn.follow(gizemsungu);

        System.out.println("\nStep 12... Sending a message to gizemsungu...");
        loggedIn.sendMessage(messageId++, gizemsungu, "This homework is too easy!");

        System.out.println("\nStep 13... Logging out from account 'gokhankaya'...");
        loggedIn.logout();

        System.out.println("\nStep 14... Logging into another account (username: gizemsungu)...");
        loggedIn = gizemsungu.login("gizemsungu");

        System.out.println("\nStep 15... Checking outbox...");
        loggedIn.checkOutbox();

        System.out.println("\nStep 16... Checking inbox...");
        loggedIn.checkInbox();

        System.out.println("\nStep 17... Viewing inbox...");
        loggedIn.viewInbox();

        System.out.println("\nStep 18... Viewing sibelgulmez's profile...");
        loggedIn.viewProfile(sibelgulmez);

        System.out.println("\nStep 19... Viewing sibelgulmez's posts...");
        loggedIn.viewPosts(sibelgulmez);

        System.out.println("\nStep 20... Viewing sibelgulmez's posts' interactions...");
        loggedIn.viewPostsInteractions(sibelgulmez);

        System.out.println("\nStep 21... Liking sibelgulmez's posts...");
        loggedIn.like(likeId++, sibelgulmez.getPosts()[0]);
        loggedIn.like(likeId++, sibelgulmez.getPosts()[1]);

        System.out.println("\nViewing sibelgulmez's posts' interactions...");
        loggedIn.viewPostsInteractions(sibelgulmez);

        long endTime = System.currentTimeMillis();
        
        long elapsedTime = endTime - startTime;
        System.out.println("Elapsed time in milliseconds: " + elapsedTime);
    }

}