import java.util.LinkedHashMap;
import java.util.Map;

public class SelectionSort{
    private MyMap originalMap;
    private MyMap sortedMap;

    /**
     * This constructor takes MyMap as original map and copies the sorted version of it 
     * to the sorted map without changing the original map.
     * 
     * @param originalMap original map to be sorted by mergesort algoirthm
     */
    SelectionSort(MyMap originalMap){
        this.originalMap = originalMap;
        sortedMap = new MyMap(originalMap.getStr());

        LinkedHashMap<String, Info> map = sortedMap.getMap();

        // cast hashmap elements to array and perform merge sort.

        Map.Entry<String, Info>[] entries = map.entrySet().toArray(new Map.Entry[map.entrySet().size()]);
        selectionSort(entries);

        // create new hashmap and include sorted entries.
        LinkedHashMap<String,Info> sorted = new LinkedHashMap<String,Info>();
        for(int i = 0; i < entries.length; ++i){
            sorted.put(entries[i].getKey(), entries[i].getValue());
        }
        // set the sorted map to the new sorted map.
        sortedMap.setMap(sorted);
    }

    private void selectionSort(Map.Entry<String, Info>[] entries) {
        int n = entries.length;

        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n-1; i++)
        {
            // Find the minimum element in unsorted array
            int min_ix = i;
            for (int j = i+1; j < n; j++)
                if (entries[j].getValue().getCount() < entries[min_ix].getValue().getCount())
                    min_ix = j;

            // Swap the found minimum element with the first element
            Map.Entry<String, Info> temp = entries[min_ix];
            entries[min_ix] = entries[i];
            entries[i] = temp;
        }
    }

    @Override
    public String toString() {
        return String.format("Original Map: \n%s\n\nSorted Map: \n%s",
             originalMap.toString(), sortedMap.toString());
    }

}