/**
 * Class that constructs a root and end nodes from all neighboring empty nodes.
 */

import java.util.HashSet;
import java.util.Stack;
import javax.swing.tree.DefaultMutableTreeNode;

public class CSE222Graph{

    private HashSet<Coordinate> coordinates;        // coordinates that are added to the graph for debug purposes.
    private DefaultMutableTreeNode root;            // root node (start point)
    private DefaultMutableTreeNode end;             // end node (end point)
    private HashSet<DefaultMutableTreeNode> nodes;  // all nodes.
    private CSE222Map map;                          // map of the graph.

    /**
     * Constructs a new CSE222Graph from the given CSE222Map.
     *  
     * @param map to be used to construct the graph.
     */
    CSE222Graph(CSE222Map map){
        this.nodes = new HashSet<>();
        this.map = map;
        this.coordinates = new HashSet<>();
        this.root = new DefaultMutableTreeNode(map.getStart());
        this.coordinates.add(map.getStart());

        fillGraph(root);
    }

    /**
     * fills graph with neighbor empty coordinates.
     * 
     * @param parent root node(start) of the graph
     */
    private void fillGraph(DefaultMutableTreeNode root) {

        Stack<DefaultMutableTreeNode> stack = new Stack<>();
        stack.push(root);
        nodes.add(root);

        while (!stack.isEmpty()) {
            DefaultMutableTreeNode parent = stack.pop();
            Coordinate parentCoordinate = (Coordinate) parent.getUserObject();

            for (Coordinate cor : parentCoordinate.getNeighbors()) {
                if (!coordinates.contains(cor) && map.getOccupied().get(cor) != null && map.getOccupied().get(cor) == false) {
                    DefaultMutableTreeNode newChild = new DefaultMutableTreeNode(cor);
                    parent.add(newChild);
                    coordinates.add(cor);
                    stack.push(newChild);
                    nodes.add(newChild);
                    if(cor.equals(map.getEnd()))
                        end = newChild;
                }
            }
        }
    }

    //gets.
    
    /**
     * 
     * @return all nodes
     * (empty nodes connected as children to root, and more empty nodes connected to them until end.)
     */
    public HashSet<DefaultMutableTreeNode> getNodes() {
        return nodes;
    }


    public int[][] getMapAsArray() {
        return map.getMapArray();
    }
    public HashSet<Coordinate> getCoordinates() {return coordinates;}
    public DefaultMutableTreeNode getRoot() {return root;}
    public DefaultMutableTreeNode getEnd() {return end;}
    public CSE222Map getMap() {return map;}
}