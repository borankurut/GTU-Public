import java.util.ArrayList;

public interface Observer{
    public void update(ArrayList<Entity> newData);
    public void setSubject(Subject s);
}
