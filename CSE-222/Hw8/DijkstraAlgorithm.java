/**
 * Dijkstra algorithm for finding shortest path from graph.
 */

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class DijkstraAlgorithm {

    private CSE222Graph graph;
    private HashSet<Coordinate> shortestPath;       //soltuion

    public DijkstraAlgorithm(CSE222Graph graph) {
        this.graph = graph;
        findShortestPath(); // constructor calls the algorithm.
    }

    private void findShortestPath() {
        Coordinate start =(Coordinate) graph.getRoot().getUserObject();
        Coordinate end = graph.getMap().getEnd();

        // distances map with infinity.
        Map<Coordinate, Double> distances = new HashMap<>();
        for (Coordinate coordinate : graph.getCoordinates()) {
            distances.put(coordinate, Double.POSITIVE_INFINITY);
        }
        // except start point.
        distances.put(start, Double.valueOf(0));


        HashSet<Coordinate> visited = new HashSet<>(); // visited set
        Deque<Coordinate> queue = new ArrayDeque<>();
        queue.offer(start);

        // Dijkstra's algorithm
        while (!queue.isEmpty()) {
            Coordinate current = queue.poll();
            Double currentDistance = distances.get(current);

            if (current.equals(end)) {
                break; 
            }

            for (Coordinate neighbor : current.getNeighbors()) {
                if (!visited.contains(neighbor) && graph.getMap().getOccupied().get(neighbor)!=null && !graph.getMap().getOccupied().get(neighbor)) {
                    queue.offer(neighbor);
                    visited.add(neighbor);


                    // Update distance if it's shorter
                    Double neighborDistance = currentDistance + getDistance(current, neighbor);     // distance between non-cross neighbors are 1.


                    if (neighborDistance < distances.get(neighbor)) {
                        distances.put(neighbor, neighborDistance);
                    }
                }
            }
        }

        // Reconstruct the shortest path
        HashSet<Coordinate> shortestPath = new HashSet<>();
        Coordinate current = end;
        shortestPath.add(current);

        while (!current.equals(start)) {
            Double currentDistance = distances.get(current);
            for (Coordinate neighbor : current.getNeighbors()) {
                if (graph.getMap().getOccupied().get(neighbor) != null && 
                        !graph.getMap().getOccupied().get(neighbor) && 
                        distances.get(neighbor) != null &&
                        distances.get(neighbor) - (currentDistance - getDistance(current, neighbor)) < 0.0001) {
                    shortestPath.add(neighbor);
                    current = neighbor;
                    break;
                }
            }
        }

        this.shortestPath = shortestPath;
    }

    /**
     * 
     * @param c1    coordinate 1
     * @param c2    coordinate 2
     * @return      distance between.
     */
    private double getDistance(Coordinate c1, Coordinate c2) {
        if (c1.isCrossPoint(c2)) {
            return Math.sqrt(2);
        } else {
            return 1.0;
        }
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

    public HashSet<Coordinate> getShortestPath() {return shortestPath;}
}