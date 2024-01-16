package homework1;

import java.io.PrintStream;

/**
 *  Class to test scenario 2.
 */

public class TestClass2{
    public static void main(String[] args) {    
        try {
            PrintStream fileStream = new PrintStream("ArrayListTestClass2Output.txt");
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

        Account gokhankaya = new Account(accountId++, "gokhankaya", 12, 10, 1990, "Istanbul");
        Account gizemsungu = new Account(accountId++, "gizemsungu", 11, 3, 1995, "Istanbul");
        Account sibelgulmez = new Account(accountId++, "sibelgulmez", 10, 3, 1995, "Istanbul");

        System.out.println("\nStep 1: 'gizemsungu' logs in.");
        loggedIn = gizemsungu.login("gizemsungu");       
        
        System.out.println("\nShares posts1 and posts2");
        loggedIn.addPost(postId++, "Post1");
        loggedIn.addPost(postId++, "Post1");

        System.out.println("\nlogs out.");
        loggedIn.logout();

        System.out.println("\nStep 2: 'sibelgulmez' logs in.");
        loggedIn = sibelgulmez.login("sibelgulmez");

        System.out.println("\na. views the profile of 'gizemsungu'.");
        loggedIn.viewProfile(gizemsungu);

        System.out.println("\nb. likes Post1.");
        loggedIn.like(likeId++, gizemsungu.getPosts().get(0));

        System.out.println("\nc. logs out.");
        loggedIn.logout();

        System.out.println("\nStep 3: 'gokhankaya' logs in.");
        loggedIn = gokhankaya.login("gokhankaya");

        System.out.println("\na. views the profile of 'gizemsungu'.");
        loggedIn.viewProfile(gizemsungu);

        System.out.println("\nb. comments on Post2 (ex: Nice!).");
        loggedIn.comment(commentId++, gizemsungu.getPosts().get(1), "Nice!");

        System.out.println("\nc. sends a message to 'gizemsungu' (ex: Hello!)");
        
        // gokhankaya need to follow gizemsungu to send message.
        loggedIn.follow(gizemsungu);

        loggedIn.sendMessage(messageId++, gizemsungu, "Hello!");

        System.out.println("\nd. logs out.");
        loggedIn.logout();

        System.out.println("Step 4: 'gizemsungu' logs in.");
        loggedIn = gizemsungu.login("gizemsungu");

        System.out.println("\na. views her own profile. and b. reads the message from 'gokhankaya'.");
        loggedIn.viewProfile(gizemsungu);

        long endTime = System.currentTimeMillis();
        
        long elapsedTime = endTime - startTime;
        System.out.println("Elapsed time in milliseconds: " + elapsedTime);
    }
}