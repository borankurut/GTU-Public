/**
 * This code implements the MyMap class specified in the pdf.
 */

import java.util.LinkedHashMap;
import java.util.Map;

public class MyMap{
    LinkedHashMap<String, Info> map;
    int mapSize;
    String str;

    /**
     * 
     * @param str String to be used as the map data.
     */
    public MyMap(String str){
        mapSize = 0;
        this.str = str;
        map = new LinkedHashMap<String, Info>();

        String[] array = str.split("\\s+");

        for(String s : array){
            for(int i = 0; i < s.length(); ++i){
                String character = Character.toString(s.charAt(i));
                if(map.containsKey(character)){
                    map.get(character).push(s);
                }
                else{
                    Info info = new Info();
                    info.push(s);
                    map.put(character, info);
                    mapSize++;
                }
            }
        }
    }

    /**
     * 
     * @return the string data of the MyMap.
     */
    public String getStr(){return str;}

    /**
     * 
     * @return LinkedHashMap of the MyMap.
     */
    public LinkedHashMap<String, Info> getMap(){return map;}

    /**
     * Sets map.
     * 
     * @param map new LinkedHashMap.
     */
    public void setMap(LinkedHashMap<String, Info> map){this.map=map;}

    @Override
    public String toString() {
        String s = ""; 
        for (Map.Entry<String, Info> entry : map.entrySet()) {
            s += (entry.getKey() + ": " + entry.getValue()) + "\n";
        }
        return s;
    }
}