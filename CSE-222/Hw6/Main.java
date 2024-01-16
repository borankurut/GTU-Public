public class Main{
    public static void main(String[] args) {
        // ex1:
        String preProcessed = "Buzzing bees buzz.";
        System.out.println(String.format("Original String: %s", preProcessed));

        String processed = preProcessed.toLowerCase().replaceAll("[^a-z\\s]", "");
        System.out.println(String.format("Processed String: %s", processed));

        MyMap myMap = new MyMap(processed);
        MergeSort ms = new MergeSort(myMap);
        System.out.println(ms);

        // ex2:
        String preProcessed2 = "'Hush, hush!' whispered the rushing wind.";
        System.out.println(String.format("Original String: %s", preProcessed2));

        String processed2 = preProcessed2.toLowerCase().replaceAll("[^a-z\\s]", "");
        System.out.println(String.format("Processed String: %s", processed2));

        MyMap myMap2 = new MyMap(processed2);
        MergeSort ms2 = new MergeSort(myMap2);
        System.out.println(ms2);

    }
}