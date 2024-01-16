import java.util.LinkedHashMap;
import java.util.Map;

public class BubbleSort{
    private MyMap originalMap;
    private MyMap sortedMap;

    /**
     * This constructor takes MyMap as original map and copies the sorted version of it 
     * to the sorted map without changing the original map.
     * 
     * @param originalMap original map to be sorted by mergesort algoirthm
     */
    BubbleSort(MyMap originalMap){
        this.originalMap = originalMap;
        sortedMap = new MyMap(originalMap.getStr());

        LinkedHashMap<String, Info> map = sortedMap.getMap();

        // cast hashmap elements to array and perform merge sort.

        Map.Entry<String, Info>[] entries = map.entrySet().toArray(new Map.Entry[map.entrySet().size()]);
        bubbleSort(entries);

        // create new hashmap and include sorted entries.
        LinkedHashMap<String,Info> sorted = new LinkedHashMap<String,Info>();
        for(int i = 0; i < entries.length; ++i){
            sorted.put(entries[i].getKey(), entries[i].getValue());
        }
        // set the sorted map to the new sorted map.
        sortedMap.setMap(sorted);
    }

    private void bubbleSort(Map.Entry<String, Info>[] entries) {
        int n = entries.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (entries[j].getValue().getCount() > entries[j + 1].getValue().getCount()) {
                    // swap arr[j+1] and arr[j]
                    Map.Entry<String, Info> temp = entries[j];
                    entries[j] = entries[j + 1];
                    entries[j + 1] = temp;
                }
            }
        }
    }

    @Override
    public String toString() {
        return String.format("Original Map: \n%s\n\nSorted Map: \n%s",
             originalMap.toString(), sortedMap.toString());
    }

}