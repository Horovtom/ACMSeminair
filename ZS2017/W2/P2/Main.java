package P2;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    private ArrayList<ArrayList<Integer>> connections;
    //private int[][] connections;
    //private int[] connectionCounts;
    private int maxDist;
    private  int numOfComputers;


    public static void main(String[] args) {
        Main m = new Main();
    }

    public Main() {
        loadData();
    }

    private void loadData() {
        Scanner sc  = new Scanner(System.in);
        int numOfCases = sc.nextInt();
        while(numOfCases-- != 0) {
            numOfComputers = sc.nextInt();
            connections = new ArrayList<>(numOfComputers);
            for (int i = 0; i < numOfComputers; i++) {
                connections.add(new ArrayList<>());
            }
            //connections = new int[numOfComputers][numOfComputers - 1];
            //connectionCounts = new int[numOfComputers];
            for (int i = 0; i < numOfComputers- 1; i++) {
                int comp1 = sc.nextInt();
                int comp2 = sc.nextInt();
                connections.get(comp1).add(comp2);
                connections.get(comp2).add(comp1);
                // /connections[comp1][connectionCounts[comp1]++] = comp2;
                //connections[comp2][connectionCounts[comp2]++] = comp1;
            }

            dfs(dfs(0));

            System.out.println((maxDist + 1) >> 1);
        }
    }

    private int dfs(int node) {
        Stack<Integer> stack = new Stack<>();
        stack.push(node);
        boolean[] visited = new boolean[numOfComputers];
        int[] distances = new int[numOfComputers];

        visited[node] = true;
        while(stack.size() != 0) {
            int curr = stack.pop();
            ArrayList<Integer> currNeighbours = connections.get(curr);
            for (Integer currNeighbour : currNeighbours) {
                int currentNeighbour = currNeighbour;
                if (!visited[currentNeighbour]) {
                    visited[currentNeighbour] = true;
                    stack.push(currentNeighbour);
                    distances[currentNeighbour] = distances[curr] + 1;
                }
            }
        }

        //find max dist
        maxDist = 0;
        int maximumComputer = 0;
        for (int i = 0; i < numOfComputers; i++) {
            if (distances[i] > maxDist) {
                maxDist  = distances[i];
                maximumComputer = i;
            }
        }

        return maximumComputer;
    }
}
