import java.util.LinkedHashMap;
import java.util.Map;

public class InsertionSort{
    private MyMap originalMap;
    private MyMap sortedMap;

    /**
     * This constructor takes MyMap as original map and copies the sorted version of it 
     * to the sorted map without changing the original map.
     * 
     * @param originalMap original map to be sorted by mergesort algoirthm
     */
    InsertionSort(MyMap originalMap){
        this.originalMap = originalMap;
        sortedMap = new MyMap(originalMap.getStr());

        LinkedHashMap<String, Info> map = sortedMap.getMap();

        // cast hashmap elements to array and perform merge sort.

        Map.Entry<String, Info>[] entries = map.entrySet().toArray(new Map.Entry[map.entrySet().size()]);
        insertionSort(entries);

        // create new hashmap and include sorted entries.
        LinkedHashMap<String,Info> sorted = new LinkedHashMap<String,Info>();
        for(int i = 0; i < entries.length; ++i){
            sorted.put(entries[i].getKey(), entries[i].getValue());
        }
        // set the sorted map to the new sorted map.
        sortedMap.setMap(sorted);
    }

    private void insertionSort(Map.Entry<String, Info> [] entries) {
        for (int i = 1; i < entries.length; i++) {
            Map.Entry<String, Info> keyEntry = entries[i];
            int j = i - 1;
            while (j >= 0 && entries[j].getValue().getCount() > keyEntry.getValue().getCount()) {
                entries[j + 1] = entries[j];
                j--;
            }
            entries[j + 1] = keyEntry;
        }
    }

    @Override
    public String toString() {
        return String.format("Original Map: \n%s\n\nSorted Map: \n%s",
             originalMap.toString(), sortedMap.toString());
    }

}