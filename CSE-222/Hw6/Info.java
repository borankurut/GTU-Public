/**
 * This code implements Info class specified in the pdf.
 */

public class Info{
    private int count;
    private String [] words;

    public Info(){
        count = 0;
        words = new String[10];
    }

    /**
     * push the element into the info.
     * 
     * @param element to be pushed.
     */
    public void push(String element){
        if(count == words.length){
            incrementSize();
        }

        words[count++] = element;
    }   

    /**
     * This code increments the size of the info, push calls this when necessary.
     */
    private void incrementSize(){
        String[] wordsNew = new String[words.length * 2];
        for(int i = 0; i < count; ++i){
            words[i] = wordsNew[i];
        }
        words = wordsNew;
    }

    /**
     * 
     * @return count of the info
     */
    public int getCount(){return count;}

    @Override
    public String toString() {
        if(count == 0)
            return "Info: []";
        String arr = "[";
        for(int i = 0; i < count; ++i){
            arr += words[i] + ", ";
        }
        arr = arr.substring(0, arr.length()-2) + "]";
        return String.format("count: %s, %s", count, arr);
    }    

}