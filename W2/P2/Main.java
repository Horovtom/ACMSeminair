package P2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by lactosis on 12.10.17.
 */
public class Main {

    int[][] nodes;
    int[] slots;

    int[] depths;

    public void getAnswer() {

        depths = new int[slots.length];
        int deepestNode = findDeepestNode(0, false);
        depths = new int[slots.length];
        findDeepestNode(deepestNode, true);
    }

    private int findDeepestNode(int v, boolean print) {

        boolean[] visited = new boolean[slots.length];
        dfsDown(v, 0, visited);

        int max = 0;
        int maxNode = 0;
        for (int i = 0; i < depths.length; i++) {
            if (depths[i] > max) {
                max = depths[i];
                maxNode = i;
            }
        }
        if (print) {
            System.out.println((int) Math.ceil(max / 2.0));
        }
        return maxNode;
    }

    private void dfsDown(int node, int depth, boolean[] visited) {
        if (visited[node]) return;
        depths[node] = depth;

        visited[node] = true;
        for (int i = 0; i < slots[node]; i++) {
            dfsDown(nodes[node][i], depth + 1, visited);
        }
        visited[node] = false;
    }

    public Main() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;

        try {
            line = br.readLine();
            int testCases = Integer.parseInt(line);

            for (int i = 0; i < testCases; i++) {
                int computers = Integer.parseInt(br.readLine());
                nodes = new int[computers][computers - 1];
                slots = new int[computers];
                for (int j = 0; j < computers - 1; j++) {
                    line = br.readLine();
                    String[] a = line.split(" ");
                    int computer1 = Integer.parseInt(a[0]);
                    int computer2 = Integer.parseInt(a[1]);

                    nodes[computer1][slots[computer1]++] = computer2;
                    nodes[computer2][slots[computer2]++]  = computer1;
                }

                getAnswer();

            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main();
    }

}
