import java.util.ArrayList;

public class Viewer implements Observer{
    private Subject dataSet;
    private ArrayList<Entity> obsData;
    private int viewingIx;

    public void setSubject(Subject s){
        if(dataSet != s){   // to prevent reseting currently viewing index if dataset is same
            dataSet = s;
            dataSet.register(this);
            viewingIx = 0;
        }
    }

    public void update(ArrayList<Entity> newData) {
        viewingIx = 0;      //update the data and reset currently viewing
        obsData = newData;
    }

    public Viewer(Subject newDataSet){
        obsData = new ArrayList<Entity>();
        dataSet = newDataSet;
        dataSet.register(this);
        viewingIx = 0;
    }

    public Viewer(){
        obsData = new ArrayList<Entity>();
        viewingIx = 0;
    }

    public void showList(){
        for(Entity e : obsData){
            if(e instanceof NonPlayable){       // if instance is viewable(nonplayable)
                NonPlayable v = (NonPlayable) e;// cast it.
                v.info();                       // print info
            }
        }
    }
    public void next(){
        viewingIx = (viewingIx+1) % obsData.size();     // compute next viewing ix 
        while(!(obsData.get(viewingIx) instanceof NonPlayable)) //until it is viewable.
            viewingIx= (viewingIx+1) % obsData.size();
    }

    public void previous(){ 
        viewingIx = (viewingIx-1 + obsData.size()) % obsData.size();    //compute previous ix
        while(!(obsData.get(viewingIx) instanceof NonPlayable))         //until it is viewable.
            viewingIx= (viewingIx-1 + obsData.size()) % obsData.size();
    }

    public NonPlayable currently_viewing(){
        boolean found = false;
        for(int i = 0; i < obsData.size(); ++i){
            if(obsData.get(i) instanceof Playable)
                found = true;
        }

        if(!found)      // there is no data to view
            throw new RuntimeException("!!No Viewable Object!!");

        while(!(obsData.get(viewingIx) instanceof NonPlayable))
            next();
        return (NonPlayable)obsData.get(viewingIx);
    }
}