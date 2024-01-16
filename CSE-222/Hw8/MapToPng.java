/**
 * Class to convert map array to png.
 */

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class MapToPng {

    /**
     * 
     * @param mapArray  2D int array, 0 represents empty, 1 represents non-empty, 2 represents path.
     * @param pathName  output file name.
     */
    public static void convert(int[][] mapArray, String pathName){
        
        int width = mapArray[0].length;
        int height = mapArray.length;

        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (mapArray[y][x] == 0) {
                    // Set the pixel to white (unoccupied)
                    image.setRGB(y, x, 0xFFFFFF);
                } else if (mapArray[y][x] == 1) {
                    // Set the pixel to black (occupied)
                    image.setRGB(y, x, 0x000000);
                }
                else{   // Set the pixel to red (path)
                    image.setRGB(y,x, 0xFF0000);
                }
            }
        }

        try {
            File output = new File(pathName);
            ImageIO.write(image, "png", output);
            System.out.println("Map image saved");
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}