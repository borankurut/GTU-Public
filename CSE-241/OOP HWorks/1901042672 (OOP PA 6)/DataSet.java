import java.util.ArrayList;

public class DataSet implements Subject{
    private ArrayList<Observer> observers;      // observers(player and viewer)
    private ArrayList<Entity> data;             // data(entities)

    public DataSet(){   // create arraylists
        observers = new ArrayList<Observer>();
        data = new ArrayList<Entity>();
    }

    public DataSet(ArrayList<Entity> newData){  // create arraylists with data
        observers = new ArrayList<Observer>();
        data = newData;
    }

    public void register(Observer o) {  
        o.setSubject(this); // observers subject is this object.
        observers.add(o);   
        notifyObservers();  // notify observers to notify o.
    }

    public void unregister(Observer o) {
        int obsIx = observers.indexOf(o);
        observers.remove(obsIx);
        System.out.println("observers[" + obsIx + "] is removed.");
    }

    public void notifyObservers() {
        for(Observer o : observers){
            o.update(data);     // update observers data.
        }
    }    

    public void add(Entity e){
        data.add(e);
        notifyObservers();
    }

    public void remove(Entity e){
        data.remove(e);
        notifyObservers();
    }
}

