public class Image extends Entity implements Visual, NonPlayable{
    private double dimX;
    private double dimY;

    public Image(String n, double x, double y){
        super(n);
        dimX = x;
        dimY = y;   //image is entity, has width and height.
    }

    public double getDimensionX(){return dimX;}
    public double getDimensionY(){return dimY;}

    public void setDimensionX(double x){dimX = x;}
    public void setDimensionY(double y){dimY = y;}

    public void info() {        //print info
        System.out.println("Image:");
        System.out.println("name: "+ name +", x: " + dimX + ", y: " + dimY);
        System.out.println();
    }
}
