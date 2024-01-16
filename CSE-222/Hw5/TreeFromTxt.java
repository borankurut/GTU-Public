/**
 * This is the class that implements returnTreeFromTxt method which returns the root node of the
 * tree that is created from the txt file in the pathName.
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import javax.swing.tree.DefaultMutableTreeNode;


public class TreeFromTxt {
    
    private static final String ROOT_LABEL = "Root";        // Root node name.
    private static final int MAX_LINE_AMOUNT = 100;         // maximum line amount in the txt file.


    /**
     * Creates a new tree from the given file in pathName and returns the root node.
     * 
     * @param pathName      path that contains the file.
     * @return              returns the root node of the created tree.
     */
    public static DefaultMutableTreeNode returnTreeFromTxt(String pathName){
        File file = new File(pathName);     // file to read

        DefaultMutableTreeNode root = new DefaultMutableTreeNode(ROOT_LABEL);   

        //  Keys in hashmap are the label of the node in the file ex:
        //  "root->2023->cse232" have root;2023;cse232 label as key in hashmap 
        //  and corresponding node as value.
        Map<String, DefaultMutableTreeNode> nodes = new HashMap<>();
        

        // 2d string array from file.
        // valuesString[0] = String["2021", "CSE102", "LECTURE1"]...
        String[][] valuesString = new String[MAX_LINE_AMOUNT][];
        int valuesStringIndex = 0;

        
        try (Scanner scanner = new Scanner(file)) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] values = line.split(";");      // split the data by ; and add to array.
                valuesString[valuesStringIndex++] = values;
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();            
        }

        for(int i = 0; i < valuesStringIndex; ++i) {
            String[] values = valuesString[i];      // current line of the data.

            // when node label is is empty, parentNode is root.
            DefaultMutableTreeNode parentNode = root;
            String nodeLabel = "";
                
            for (String value : values) {

                nodeLabel += value + ";";       // update nodeLabel by given value.
                
                // there is no label in the hashmap, so node isn't created yet.
                if (!nodes.containsKey(nodeLabel)) {    
                    
                    DefaultMutableTreeNode node = new DefaultMutableTreeNode(value);
                    parentNode.add(node);  

                    nodes.put(nodeLabel, node);

                    // last created node is the parrent of the next data in the line.
                    parentNode = node;
                }

                // the node is added earlier, so update the parent.
                else
                    parentNode = nodes.get(nodeLabel);  
            }
        }
        return root;
    }
}