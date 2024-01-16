public class UsernameChecker{

    /**
     * 
     * @param username  username to check
     * @return          whether username is valid    
     */
    static public boolean check(String username) throws InvalidPairException{
        return UsernameChecker.checkIfValidUsername(username);
    }
    
    static private boolean validUsernameHelper(String s){
        if(s.length() == 0) // all characters checked.
            return true;

        if(!Character.isAlphabetic(s.charAt(0)))    // character is not alphabetic.
            return false;
        else 
            return validUsernameHelper(s.substring(1)); // check the rest.
    }

    /**
     * 
     * @param username  username to check.
     * @return          whether username is at least one character and its characters are alphabetic.
     */
    static private boolean checkIfValidUsername(String username) throws InvalidPairException{ 
        if(username.length() < 1){
            throw new InvalidPairException("Username is invalid (its length is less than 1)");
        }
        boolean result = validUsernameHelper(username);

        if(!result){
            throw new InvalidPairException("Username is invalid (characters are not alphabetic)");
        }
        return result;
    }
}
