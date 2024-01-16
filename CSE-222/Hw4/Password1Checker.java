import java.util.EmptyStackException;
import java.util.Stack;

public class Password1Checker{

    static private final String brackets = "([{}])";

    /**
     * 
     * @param username      the username
     * @param password1     password to check
     * @return              whether password is valid
     */
    static public boolean check(String username, String password1) throws InvalidPairException{

        if(password1.length() < 8)
            throw new InvalidPairException("Password must be at least 8 characters");

        if(!containsOnlyLetterAndBrackets(password1))
            throw new InvalidPairException("password1 must contain only letters and brackets");
        
        if(!containsAtLeastTwoBrackets(password1))
            throw new InvalidPairException("password1 must contain at least two brackets");
        
        return  Password1Checker.containsUserNameSpirit(username, password1) &&
                Password1Checker.isBalancedPassword(password1)              &&
                Password1Checker.isPalindromePossible(password1);
    }

    static private boolean containsOnlyLetterAndBrackets(String password1){
        for(int i = 0; i < password1.length(); ++i){
            if( !Character.isAlphabetic(password1.charAt(i)) && 
                !brackets.contains(String.valueOf(password1.charAt(i)))){

                return false;
            }
        }
        return true;
    } 

    static private boolean containsAtLeastTwoBrackets(String password1){
        int count = 0;
        for(int i = 0; i < password1.length(); ++i){
            if(brackets.contains(String.valueOf(password1.charAt(i))))
                count++;
        }
        return count >= 2;
    }

    /**
     * This method checks how many of characters that occured odd times in the s.
     * if odd occured characters are more than 1, the string cannot be palindrome.
     * 
     * @param s     string to check whether possible palindrome.
     * @param odds  the amount of characters that are occured odd number of times in s.
     * @return      true if possible palindrome
     */
    static private boolean palindromeHelper(String s, int odds){
        if(odds > 1)            // can't be palindrome.
            return false;
            
        if(s.length() == 0)     // all characters checked.
            return true;
        
        char toCheck = s.charAt(0);             // character to check
        int amount = 1;                               // amount of times character occurred in s.
        for(int i = 1; i < s.length(); ++i){
            if(s.charAt(i) == toCheck){
                amount++;                             // calculate occured amount.
            }
        }

        // remove the occurences of the character that is checked.
        s = s.replace(Character.toString(toCheck), ""); 

        if(amount % 2 == 1)     // occured odd number of times, increment odds.
            odds++;
        return(palindromeHelper(s, odds));  // check the remaining characters.
    }

    /**
     * 
     * @param password1 password to check
     * @return          whether the password is a possible palindrome.
     */
    static private boolean isPalindromePossible(String password1) throws InvalidPairException{
        String toCheck = new String(password1.toLowerCase());
        toCheck = toCheck.replaceAll("[^a-zA-Z]", "");

        boolean result = palindromeHelper(toCheck, 0);
        if(!result) 
            throw new InvalidPairException("password1 is invalid (password should be possible palindrome.)");
        return result;
    }

    static private boolean containsUserNameSpirit(String username, String password1) throws InvalidPairException{
        Stack<Character> stack = new Stack<Character>();

        for(int i = 0; i < username.length(); ++i){
            stack.push(username.charAt(i));
        }
        // convert username to stack..


        while(!stack.empty()){
            //
            Character ch = stack.pop();                     
            for(int i = 0; i < password1.length(); ++i)
                if(password1.charAt(i) == ch)
                    return true;
        }

        throw new InvalidPairException("password1 is invalid (does not contain a letter that is in the username)");
    }

    /**
     * 
     * @param password1 password to check
     * @return          whether the passwords brackets are valid.
     */
    static private boolean isBalancedPassword(String password1) throws InvalidPairException{
        String toCheck = password1.replaceAll("[a-zA-Z]", "");

        Stack<Character> stack = new Stack<Character>();

        try{
            for(int i = 0; i < toCheck.length(); ++i){
                Character current = toCheck.charAt(i);
                if(current == '{' || current == '[' || current == '(')
                stack.add(current);
                else if(current == '}'){
                    if(stack.pop() != '{'){
                        throw new InvalidPairException("The string password is invalid (bracket types are not matching)");
                    }
                }
                else if(current == ']'){
                    if(stack.pop() != '['){
                        throw new InvalidPairException("The string password is invalid (bracket types are not matching)");
                    }
                }
                else if(current == ')'){
                    if(stack.pop() != '('){
                        throw new InvalidPairException("The string password is invalid (bracket types are not matching)");
                    }
                }
            }
        }
        catch(EmptyStackException e){
            throw new InvalidPairException("The string password is invalid (open brackets not matching with closed brackets)");
        }
        if(!stack.empty()){
            throw new InvalidPairException("The string password is invalid (closed brackets not matching with open brackets)");
        }

        return true;
    }
}
