public class Main{
    public static void main(String[] args) {
        DataSet ds = new DataSet();//Lets create different observers.
        Player p1 = new Player();   //create a player
        Viewer v1 = new Viewer();   //create a viewer

        ds.register(p1);//register p1 and v1
        ds.register(v1);

        //createing entities.
        Image im1 = new Image("imagename1", 1, 1);
        Image im2 = new Image("imagename2", 2, 2);

        Audio au1 = new Audio("audioname1", 1.0);
        Audio au2 = new Audio("audioname2", 2.0);

        Video vi1 = new Video("videoname1", 1, 1, 1.0);
        Video vi2 = new Video("videoname2", 2, 2, 2.0);

        Text t1 = new Text("text1", 11);
        Text t2 = new Text("text2", 22);

        // adding entities to dataset.
        ds.add(im1);
        ds.add(im2);
        ds.add(au1);
        ds.add(au2);
        ds.add(vi1);
        ds.add(vi2);
        ds.add(t1);
        ds.add(t2);

        //tests
        Playable po = p1.currently_playing();
        System.out.println("p1 currently playing this:");
        po.info();

        ds.remove((Entity)po);

        System.out.println("removed");

        System.out.println("and started to play this:");
        p1.currently_playing().info();


        NonPlayable np = v1.currently_viewing();
        System.out.println("v1 currently viewing this:");
        np.info();

        v1.previous();
        System.out.println("v1 after previous() viewing this:");
        v1.currently_viewing().info();

        System.out.println("v1.showlist:");
        v1.showList();

        System.out.println("p1.showlist: ");
        p1.showList();

        ds.remove(im2);
        ds.remove(au1);
        ds.remove(au2);
        ds.remove(vi2);
        ds.remove(t1);
        ds.remove(t2);        

        System.out.println("v1.showlist:(after all elements removed except vi1 and im1):");
        v1.showList();
        System.out.println("p1.showlist:(after all elements removed except vi1 and im1):");
        p1.showList();

        System.out.println("v1 is viewing this: (after all elements removed except vi1 and im1):");
        v1.currently_viewing().info();

        System.out.println("p1 is playing this: (after all elements removed except vi1 and im1):");
        p1.currently_playing().info();

    }
}
