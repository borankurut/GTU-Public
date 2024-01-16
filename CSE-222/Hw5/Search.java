/**
 * This class contains the search algorithms for the specified methods in the pdf.
 */

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

import javax.swing.tree.DefaultMutableTreeNode;

public class Search{
    /**
     * Find the value in the tree using bfs algorithm.
     * @param root      the root node of tree to search in
     * @param value     the value to search
     */
    public static void findBFS(DefaultMutableTreeNode root, Object value){
        Deque<DefaultMutableTreeNode> deque = new ArrayDeque<DefaultMutableTreeNode>();
        deque.offer(root);

        int i = 0;
        boolean found = false;
        while(!deque.isEmpty()){
            DefaultMutableTreeNode toLook = deque.poll();
            System.out.print("Step " + (++i) + " -> ");
            System.out.println(toLook.getUserObject());
            if(toLook.getUserObject().equals(value)){
                found = true;
                System.out.println("Found!");
                break;
            }
            else{
                for(int j = 0; j < toLook.getChildCount(); ++j){
                    deque.offer((DefaultMutableTreeNode) toLook.getChildAt(j));
                }
            }
        }

        if(!found)
            System.out.println("Not found.");
    }

    /**
     * Find the value in the tree using dfs algorithm.
     * @param root      the root node of tree to search in
     * @param value     the value to search
     */
    public static void findDFS(DefaultMutableTreeNode root, Object value){
        Stack<DefaultMutableTreeNode> stack = new Stack<>();
        stack.push(root);
        int step = 0;

        while(!stack.empty()){
            DefaultMutableTreeNode toLook = stack.pop();    

            System.out.print("Step " + (++step) + " -> ");
            System.out.println(toLook.getUserObject());

            if(toLook.getUserObject().equals(value)){
                System.out.println("Found!");
                return;
            }
            else
                for(int i = toLook.getChildCount() - 1; i >= 0; --i)
                    stack.push((DefaultMutableTreeNode) toLook.getChildAt(i));
        }
        System.out.println("Not found.");
    }

    /**
     * Find the value in the tree using post traversal algorithm.
     * @param root      the root node of tree to search in
     * @param value     the value to search
     */

    public static void findPostTraversal(DefaultMutableTreeNode root, Object value){
        int step[] = {1};
        if(!findPostTraversalHelper(root, value, step))
            System.out.println("Not found.");
    }

    private static boolean findPostTraversalHelper(DefaultMutableTreeNode current, Object value, int[] step){
        if(current.getUserObject().equals(value)){
            System.out.print("Step " + (step[0]++) + " -> ");
            System.out.println(current.getUserObject());
            System.out.println("Found!");
            return true;
        }
        boolean toReturn = false;
        if(!current.isLeaf())
            for(int i = 0; i < current.getChildCount(); ++i){
                toReturn = toReturn || findPostTraversalHelper((DefaultMutableTreeNode)current.getChildAt(i), value, step);
            }

        if(toReturn)
            return true;
        
        System.out.print("Step " + (step[0]++) + " -> ");
        System.out.println(current.getUserObject());

        return toReturn;
    }

}
