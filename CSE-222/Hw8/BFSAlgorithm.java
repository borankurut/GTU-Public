/**
 * BFS algorithm for finding the shortest path from given graph.
 */

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;

public class BFSAlgorithm {

    private CSE222Graph graph;
    private HashSet<Coordinate> shortestPath;

    public BFSAlgorithm(CSE222Graph graph) {
        this.graph = graph;
        findShortestPath(); //constructor calls the algorithm.
    }

    private void findShortestPath() {
        Coordinate start = graph.getMap().getStart();
        Coordinate end = graph.getMap().getEnd();

        // Initialize visited set and queue
        HashSet<Coordinate> visited = new HashSet<>();
        Deque<Coordinate> queue = new ArrayDeque<>();
        queue.offer(start);
        visited.add(start);

        // we need this for traversing backwards.
        HashMap<Coordinate, Coordinate> parentMap = new HashMap<>();
        parentMap.put(start, null);

        // BFS algorithm
        while (!queue.isEmpty()) {
            Coordinate current = queue.poll();

            if (current.equals(end)) {
                break; // found the shortest path to the end coordinate
            }

            for (Coordinate neighbor : current.getNeighbors()) {
                if (!visited.contains(neighbor) && graph.getMap().getOccupied().get(neighbor)!=null && !graph.getMap().getOccupied().get(neighbor)) {
                    queue.offer(neighbor);
                    visited.add(neighbor);
                    parentMap.put(neighbor, current);
                }
            }
        }

        // reconstruct the shortest path (traversing backwards)
        Coordinate current = end;
        HashSet<Coordinate> shortestPath = new HashSet<>();
        shortestPath.add(current);

        while (current != start) {
            Coordinate parent = parentMap.get(current);
            if (parent != null) {
                shortestPath.add(parent);
            }
            current = parent;
        }
        this.shortestPath = shortestPath;
    }

    /**
     * Clones the provided array
     * 
     * @param src
     * @return a new clone of the provided array
     */
    private static int[][] cloneArray(int[][] src) {
        int length = src.length;
        int[][] target = new int[length][src[0].length];
        for (int i = 0; i < length; i++) {
            for(int j = 0; j < src[i].length; j++) {
                target[i][j] = src[i][j];
            }
        }
        return target;
    }

    /**
     * 
     * @return returns the soltuion map array by traversing shortest path.
     */
    public int[][] getSolution() {
        int[][] toReturn = cloneArray(graph.getMapAsArray());
        
        // Puts 2's where the shortest path located to paint the path.
        for(Coordinate c : shortestPath)
           toReturn[c.getY()][c.getX()] = 2;       

        return toReturn;
    }
}