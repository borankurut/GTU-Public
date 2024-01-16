public class Main{

    public static void main(String[] args) {

        Pair[] inputs = new Pair[11];
        inputs[0] = new Pair("sibelgulmez", "[rac()ecar]", 74);
        inputs[1] = new Pair("", "[rac()ecar]", 74);
        inputs[2] = new Pair("sibel1", "[rac()ecar]", 74);
        inputs[3] = new Pair("sibel", "pass[]", 74);
        inputs[4] = new Pair("sibel", "abcdabcd", 74);
        inputs[5] = new Pair("sibel", "[[[[]]]]", 74);
        inputs[6] = new Pair("sibel", "[no](no)", 74);
        inputs[7] = new Pair("sibel", "[rac()ecar]]", 74);
        inputs[8] = new Pair("sibel", "[rac()ecars]", 74);
        inputs[9] = new Pair("sibel", "[rac()ecar]", 5);
        inputs[10] = new Pair("sibel", "[rac()ecar]", 35);

        for(int i = 0; i < inputs.length; ++i){
            
            try{
                System.out.println("Test " + (i + 1));
                System.out.println("Output for inputs: " + inputs[i]);
                if(check(inputs[i].username, inputs[i].password1, inputs[i].password2, new int[]{4, 17, 29}))
                System.out.println("The username and passwords are valid. The door is opening, please wait...\n");
            }
            catch(InvalidPairException ipE){
                System.out.println(ipE.getMessage());
                System.out.println("Try again...\n");
                continue;
            }
        }
    }

    static private class Pair{
        private String username;
        private String password1;
        private int password2;
        Pair(String username, String password1, int password2){
            this.username = username;
            this.password1 = password1;
            this.password2 = password2;
        }
        @Override
        public String toString() {
            return username + " " + password1 + " " + password2;
        }
    }

    public static boolean check(String username, String password1, int password2, int[] denominations) throws InvalidPairException{
        return      UsernameChecker.check(username)                 &&
                    Password1Checker.check(username, password1)     &&
                    Password2Checker.check(password2, denominations); 

    }
}
