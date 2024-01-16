import java.io.File;

public class TestCases implements Runnable {

    private  String FileName;
    private int X_SIZE;
    private int Y_SIZE;

    public TestCases(String FileName, int X_SIZE, int Y_SIZE) {
        this.FileName = FileName;
        this.X_SIZE = X_SIZE;
    	this.Y_SIZE = Y_SIZE;
    }
  
    
    public void test(){
    	
    	System.out.println("\n\n*******************\nMap is " + this.FileName + " with X_SIZE " + this.X_SIZE + " and Y_SIZE " + this.Y_SIZE + "\n********************\n");
        String folderName = "TextFiles";
        File file = new File(folderName, this.FileName);
        CSE222Map map = new CSE222Map(file, this.Y_SIZE, this.X_SIZE);
        CSE222Graph graph = new CSE222Graph(map);

        DijkstraAlgorithm dijkstra = new DijkstraAlgorithm(graph);
        BFSAlgorithm bfs = new BFSAlgorithm(graph);

        String outName = FileName.substring(0, FileName.length() - 4);
        WritePath.writePath(dijkstra.getShortestPath(), outName + "solution.txt");
        MapToPng.convert(map.getMapArray(), outName + ".png");
        MapToPng.convert(dijkstra.getSolution(), outName + "_solution_dijkstra.png");
        MapToPng.convert(bfs.getSolution(), outName + "_solution_bfs.png");
    }

    @Override
    public void run() {
        test();
    }
}

