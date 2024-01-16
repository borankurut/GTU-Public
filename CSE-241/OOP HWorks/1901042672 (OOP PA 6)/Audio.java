public class Audio extends Entity implements Playable, NonVisual{
    private double duration; // minutes

    public Audio(String n, double dur){
        super(n);
        duration = dur; //audio is entity and has duration.
    }

    public double getDuration() {return duration;}
    public void setDuration(double dur){duration = dur;}

    public void info() {    //print info
        System.out.println("Audio:");
        System.out.println("name:" + name + ", duration: " + duration);
        System.out.println();
    }
}
