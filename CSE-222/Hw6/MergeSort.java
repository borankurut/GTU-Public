import java.util.LinkedHashMap;
import java.util.Map;

public class MergeSort{
    private MyMap originalMap;
    private MyMap sortedMap;

    /**
     * This constructor takes MyMap as original map and copies the sorted version of it 
     * to the sorted map without changing the original map.
     * 
     * @param originalMap original map to be sorted by mergesort algoirthm
     */
    MergeSort(MyMap originalMap){
        this.originalMap = originalMap;
        sortedMap = new MyMap(originalMap.getStr());

        LinkedHashMap<String, Info> map = sortedMap.getMap();

        // cast hashmap elements to array and perform merge sort.

        Map.Entry<String, Info>[] entries = map.entrySet().toArray(new Map.Entry[map.entrySet().size()]);
        sort(entries, 0, entries.length - 1);

        // create new hashmap and include sorted entries.
        LinkedHashMap<String,Info> sorted = new LinkedHashMap<String,Info>();
        for(int i = 0; i < entries.length; ++i){
            sorted.put(entries[i].getKey(), entries[i].getValue());
        }
        // set the sorted map to the new sorted map.
        sortedMap.setMap(sorted);
    }


    /**
     * Classic merge sort algorithms merge part.
     * 
     * @param entries   entries array of the map.
     * @param l left
     * @param m middle
     * @param r right
     */
    private void merge(Map.Entry<String, Info> [] entries , int l, int m, int r)
    {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;
 
        //Create temp arrays 
        Map.Entry<String, Info>[] L = new Map.Entry[n1];

        Map.Entry<String, Info>[] R = new Map.Entry[n2];

 
        //Copy data to temp arrays
        for (int i = 0; i < n1; ++i)
            L[i] = entries[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = entries[m + 1 + j];
 
        /* Merge the temp arrays */
 
        // Initial indexes of first and second subarrays
        int i = 0, j = 0;
 
        // Initial index of merged subarray array
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i].getValue().getCount() <= R[j].getValue().getCount()) {
                entries[k] = L[i];
                i++;
            }
            else {
                entries[k] = R[j];
                j++;
            }
            k++;
        }
 
        //Copy remaining elements
        while (i < n1) {
            entries[k] = L[i];
            i++;
            k++;
        }
 
        while (j < n2) {
            entries[k] = R[j];
            j++;
            k++;
        }
    }
 
    /**
     * Classic merge sort algorithm sort part.
     * 
     * @param entries   array to be sorted
     * @param l         starting index.
     * @param r         last index
     */
    private void sort(Map.Entry<String, Info> [] entries, int l, int r)
    {
        if (l < r) {
            // Find the middle 
            int m = l + (r - l) / 2;
 
            // Sort first and second parts
            sort(entries, l, m);
            sort(entries, m + 1, r);
 
            // Merge the sorted first and second parts
            merge(entries, l, m, r);
        }
    }

    @Override
    public String toString() {
        return String.format("Original Map: \n%s\n\nSorted Map: \n%s",
             originalMap.toString(), sortedMap.toString());
    }
}