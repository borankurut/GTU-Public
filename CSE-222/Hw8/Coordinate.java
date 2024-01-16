/**
 * Class to make it easier to work with Map coordinates.
 */
import java.util.ArrayList;
import java.util.Objects;

public class Coordinate{
    private int y;
    private int x;

    /**
     * Constructs a Coordinate
     * 
     * @param y y value of the coordinate
     * @param x x value of the coordinate
     */
    Coordinate(int y, int x) {this.y=y;this.x=x;}

    // gets.
    public int getY() {return y;}
    public int getX() {return x;}

    /**
     * 
     * @param cor   coordinate to be checked
     * @return      true if this coordinate is the neighbor of the cor.
     */
    public boolean isNeighbor(Coordinate cor){
        return  (cor.y == this.y - 1 && cor.x == this.x)        || 
                (cor.y == this.y + 1 && cor.x == this.x)        ||
                (cor.y == this.y && cor.x == this.x - 1)        ||
                (cor.y == this.y && cor.x == this.x + 1)        ||
                (cor.y == this.y - 1 && cor.x == this.x - 1)    ||
                (cor.y == this.y - 1 && cor.x ==  this.x + 1)   ||
                (cor.y == this.y + 1 && cor.x == this.x + 1)    ||
                (cor.y == this.y + 1 && cor.x == this.x - 1);
    }

    public boolean isCrossPoint(Coordinate cor){
        return (cor.y == this.y - 1 && cor.x == this.x - 1)    ||
        (cor.y == this.y - 1 && cor.x ==  this.x + 1)   ||
        (cor.y == this.y + 1 && cor.x == this.x + 1)    ||
        (cor.y == this.y + 1 && cor.x == this.x - 1);
    }

    /**
     * 
     * @return the neighbors of this coordinate as an arraylist.
     */
    public ArrayList<Coordinate> getNeighbors(){
        ArrayList<Coordinate> result = new ArrayList<Coordinate>();
        result.add(new Coordinate(this.y - 1, this.x));
        result.add(new Coordinate(this.y + 1, this.x));
        result.add(new Coordinate(this.y, this.x - 1));
        result.add(new Coordinate(this.y, this.x + 1));
        result.add(new Coordinate(this.y - 1, this.x - 1));
        result.add(new Coordinate(this.y - 1, this.x + 1));
        result.add(new Coordinate(this.y + 1, this.x + 1));
        result.add(new Coordinate(this.y + 1, this.x - 1));

        return result;
    }    

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Coordinate other = (Coordinate) obj;
        return y == other.y && x == other.x;
    }

    @Override
    public int hashCode() {
        return Objects.hash(y, x);
    }

    @Override
    public String toString() {
        return String.format("(x:%s, y:%s)", x, y);
    }
}
