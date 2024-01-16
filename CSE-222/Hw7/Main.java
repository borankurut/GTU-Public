public class Main{
    public static void main(String[] args) {
        System.out.println("BEST-CASE: ");
        test("a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj");

        System.out.println("AVG CASE: ");
        test("a ccc bb ffffff dddd eeeee iiiiiiiii hhhhhhhh ggggggg jjjjjjjjjj");

        System.out.println("WORST CASE:");
        test("jjjjjjjjjj iiiiiiiii hhhhhhhh ggggggg ffffff eeeee dddd ccc bb a");
    }

    static void test(String preProcessed){
        String processed = preProcessed.toLowerCase().replaceAll("[^a-z\\s]", "");
        System.out.println("Text: " + processed);
        MyMap myMap = new MyMap(processed);

        System.out.println("SELECTION SORT:");
        SelectionSort selectionSort = new SelectionSort(myMap);
        System.out.println(selectionSort);

        System.out.println("BUBBLE SORT:");
        BubbleSort bubbleSort = new BubbleSort(myMap);
        System.out.println(bubbleSort);


        System.out.println("INSERTION SORT:");
        InsertionSort insertionSort = new InsertionSort(myMap);
        System.out.println(insertionSort);
    }
}