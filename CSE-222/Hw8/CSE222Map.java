import java.io.File;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CSE222Map{
    private Map<Coordinate, Boolean> occupied;
    private Coordinate start;
    private Coordinate end;
    public int maxY;
    public int maxX;
    private int[][] mapArray;


    public Coordinate getStart() {
        return start;
    }

    public Coordinate getEnd() {
        return end;
    }

    public Map<Coordinate, Boolean> getOccupied() {
        return occupied;
    }

    public int[][] getMapArray(){return mapArray;}

    /**
     * Constructs a new CSE222Map
     * 
     * @param file file containing Map coordinates.
     */
    public CSE222Map(File file, int maxY, int maxX){
        occupied = new HashMap<Coordinate, Boolean>();
        this.maxX = maxX;
        this.maxY = maxY;
        mapArray = new int[maxY][maxX];
        try{
            Scanner scanner = new Scanner(file);
            String[] startPoint = scanner.nextLine().split(",");
            String[] endPoint = scanner.nextLine().split(",");

            int startY = Integer.parseInt(startPoint[0]);
            int startX = Integer.parseInt(startPoint[1]);
            start = new Coordinate(startY, startX);
            mapArray[startY][startX] = 0;

            int endY = Integer.parseInt(endPoint[0]);
            int endX = Integer.parseInt(endPoint[1]);
            end = new Coordinate(endY, endX);
            mapArray[endY][endX] = 0;

            int k = 0;
            while(scanner.hasNextLine()){
                String[] ocup = scanner.nextLine().split(",");
                for(int i = 0; i < ocup.length; ++i){
                    boolean o = true;   //  some maps have -1 as occupied instead of 1, 
                                        //  so I assumed 'o' is true and checked for 0

                    if(ocup[i].equals("0")) 
                        o = false;
                    occupied.put(new Coordinate(k, i), o);
                    mapArray[k][i] = o ? 1 : 0;
                }
                ++k;
            }
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }

    @Override
    public String toString() {
        return String.format("Start: %s\nEnd: %s\nOccupied:\n%s", start, end, occupied.toString());
    }
}
