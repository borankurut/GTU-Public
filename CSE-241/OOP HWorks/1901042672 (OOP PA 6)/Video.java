public class Video extends Entity implements Visual, Playable{
    private double dimX;
    private double dimY;
    private double duration;

    public Video(String n, double x, double y, double dur){
        super(n);
        dimX = x;           //video is entity with width, height and duration
        dimY = y;
        duration = dur;
    }

    public double getDimensionX(){return dimX;}
    public double getDimensionY(){return dimY;}
    public void setDimensionX(double x){dimX = x;}
    public void setDimensionY(double y){dimY = y;}

    public double getDuration(){return duration;}
    public void setDuration(double dur){duration = dur;}

    public void info() {        //print info of the video
        System.out.println("video:");
        System.out.println("name:" +name +", x: " + dimX + ", y: " + dimY + ", duration: " + duration);
        System.out.println();
    }
}