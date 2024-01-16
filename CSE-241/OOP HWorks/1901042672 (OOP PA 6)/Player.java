import java.util.ArrayList;

public class Player implements Observer{    // same with viewer.
    private Subject dataSet;
    public ArrayList<Entity> obsData;
    private int playingIx;

    public void setSubject(Subject s){
        if(dataSet != s){    
            dataSet = s;
            dataSet.register(this);
            playingIx = 0;
        }
    }

    public void update(ArrayList<Entity> newData) {
        playingIx = 0;
        obsData = newData;
    }

    public Player(Subject newDataSet){
        obsData = new ArrayList<Entity>();
        dataSet = newDataSet;
        dataSet.register(this);
        playingIx = 0;
    }
    public Player(){
        obsData = new ArrayList<Entity>();
        playingIx = 0;
    }

    public void showList(){
        for(Entity e : obsData){
            if(e instanceof Playable){
                Playable p = (Playable) e;
                p.info();
            }
        }
    }

    public void next(){
        playingIx = (playingIx+1) % obsData.size();
        while(!(obsData.get(playingIx) instanceof Playable))
            playingIx= (playingIx+1) % obsData.size();
    }
    
    public void previous(){
        playingIx= (playingIx-1 + obsData.size()) % obsData.size();
        while(!(obsData.get(playingIx) instanceof Playable))
            playingIx= (playingIx-1 + obsData.size()) % obsData.size();
    }

    public Playable currently_playing(){
        boolean found = false;
        for(int i = 0; i < obsData.size(); ++i){
            if(obsData.get(i) instanceof Playable)
                found = true;
        }

        if(!found)
            throw new RuntimeException("!!No Playable Object!!");

        while(!(obsData.get(playingIx) instanceof Playable))
            next();
        return (Playable)obsData.get(playingIx);
    }   
}