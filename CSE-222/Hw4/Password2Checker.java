public class Password2Checker{    

    /**
     * 
     * @param password2         password to check
     * @param denominations     denominations
     * @return                  whether password is valid
     */
    public static boolean check(int password2, int [] denominations) throws InvalidPairException{
        if(!betweenValidRange(password2))
            throw new InvalidPairException("Password2 must be between 10 and 10000");

        return isExactDivision(password2, denominations);
    }

    static private boolean betweenValidRange(int password2){
        int min = 10;
        int max = 10000;

        return min <= password2 && password2 <= max;
    }


    /**
     * This method adds the denominations recursively to obtain the number.
     * 
     * @param num           number to check.
     * @param sum           current sum.
     * @param denominations denominations.
     * @return
     */
    static private boolean divisionHelper(int num, int sum, int [] denominations){
        if(num == sum)          // num is found.
            return true;
        if(sum > num)           // no need to check other additions.
            return false;
        
        else{
            boolean result = false;     
            for(int i = 0; i < denominations.length; ++i){
                
                // add the denominations to sum seperately and recursively.
                result = result || divisionHelper(num, sum + denominations[i], denominations);  

                if(result)  // if result is found no need to check the remaining denominations.
                    break;
            }
            return result;
        }
    }

    /**
     * 
     * @param password2     password to check.
     * @param denominations denominations
     * @return              whether the password is obtainable by adding the denominations.
     */
    static private boolean isExactDivision(int password2, int [] denominations) throws InvalidPairException{
        boolean result = divisionHelper(password2, 0, denominations);
        if(!result)
            throw new InvalidPairException("password2 is invalid (it is not obtainable by adding the denominations.)");

        return result;
    }
}
