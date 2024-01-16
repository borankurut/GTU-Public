import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

public class WritePath {
    public static void writePath(HashSet<Coordinate> path, String filePath) {
        
        String content = "Path: ";
        for(Coordinate c : path) {
            content += c.toString() + " ";
        }
        
        try {
            FileWriter writer = new FileWriter(filePath);
            writer.write(content);
            writer.close();
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}