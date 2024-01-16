import java.util.Scanner;

import javax.swing.JFrame;
import javax.swing.JTree;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;

public class Main{
    private static final String PATH_NAME = "tree.txt";
    public static void main(String[] args) {

        DefaultMutableTreeNode root = TreeFromTxt.returnTreeFromTxt(PATH_NAME);

        DefaultTreeModel model = new DefaultTreeModel(root);
        JTree tree = new JTree(model);
        JFrame frame = new JFrame("Tree From Txt");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(tree);
        frame.setSize(300, 400);
        frame.setVisible(true);
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.print("Enter value to search > ");
            String toSearch = sc.next();

            System.out.println(String.format("Using BFS to find '%s' in the tree...", toSearch));
            Search.findBFS(root, toSearch);
            System.out.println();

            System.out.println(String.format("Using DFS to find '%s' in the tree...", toSearch));
            Search.findDFS(root, toSearch);
            System.out.println();

            System.out.println(String.format("Using Post-Order traversal to find " +
                "'%s' in the tree...", toSearch));
                
            Search.findPostTraversal(root, toSearch);
            System.out.println();
        }
    }
}
