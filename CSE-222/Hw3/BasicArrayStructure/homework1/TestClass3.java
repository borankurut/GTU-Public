package homework1;

import java.io.PrintStream;
import homework1.Account;

/**
 * Class to test scenario 3.
 */

 public class TestClass3{
    public static void main(String[] args) {
        try{
            PrintStream fileStream = new PrintStream("BasicArrayListTestClass3Output.txt");
            System.setOut(fileStream);
        }
        catch(Exception e){
            System.out.println(e);
        }

        long startTime = System.currentTimeMillis();

        int accountId = 0;
        int postId = 1;
        int messageId = 0;
        int commentId = 0;
        int likeId = 0;

        Account gokhankaya = new Account(accountId++, "gokhankaya", 12, 10, 1990, "Istanbul");
        Account gizemsungu = new Account(accountId++, "gizemsungu", 11, 3, 1995, "Istanbul");
        Account sibelgulmez = new Account(accountId++, "sibelgulmez", 10, 3, 1995, "Istanbul");

        Account loggedIn;

        // all accounts follow each other to show the block functionality.
        gokhankaya.login("gokhankaya");
        gokhankaya.follow(gizemsungu);
        gokhankaya.follow(sibelgulmez);
        gokhankaya.logout();

        gizemsungu.login("gizemsungu");
        gizemsungu.follow(gokhankaya);
        gizemsungu.follow(sibelgulmez);
        gizemsungu.logout();

        sibelgulmez.login("sibelgulmez");
        sibelgulmez.follow(gokhankaya);
        sibelgulmez.follow(gizemsungu);
        sibelgulmez.logout();

        //  1. “gizemsungu” logs in. 
        //      a. blocks “sibelgulmez”. b. logs out.
        //  2. “sibelgulmez” logs in. 
        //      a. tries to view the profile of “gizemsungu”.
        //      b. tries to send a message to “gizemsungu”.

        System.out.println("\n1. 'gizemsungu' logs in.");
        loggedIn = gizemsungu.login("gizemsungu");

        System.out.println("\na. blocks 'sibelgulmez'.");
        loggedIn.block(sibelgulmez);

        System.out.println("\nb. logs out.");
        loggedIn.logout();

        System.out.println("\n2. 'sibelgulmez' logs in.");
        loggedIn = sibelgulmez.login("sibelgulmez");

        System.out.println("\na. tries to view the profile of 'gizemsungu'");
        loggedIn.viewProfile(gizemsungu);

        System.out.println("\nb. tries to send a message to 'gizemsungu'");
        loggedIn.sendMessage(messageId++, gizemsungu, "you blocked me!");

        long endTime = System.currentTimeMillis();
        long elapsedTime = endTime - startTime;
        System.out.println("Elapsed time in milliseconds: " + elapsedTime);
    }
}