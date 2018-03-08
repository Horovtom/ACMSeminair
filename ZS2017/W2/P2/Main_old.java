package P2;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Created by lactosis on 12.10.17.
 */
public class Main_old {

    private int[][] nodes;
    private int[] slots;
    private int[] depths;

    private void getAnswer() {

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
            System.out.println((max + 1) >> 1);
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

    private void readData() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        try {
            String line;
            do {
                line = br.readLine();
            } while (line == null || line.equals(""));
            st = new StringTokenizer(line, " ");
            int numOfCases = Integer.parseInt(st.nextToken());
            while(numOfCases-- != 0) {
                do {
                    line = br.readLine();
                } while (line == null || line.equals(""));
                st = new StringTokenizer(line, " ");
                int numOfComputers = Integer.parseInt(st.nextToken());
                if (numOfComputers <= 0) {
                    System.out.println(0);
                    continue;
                }
                nodes = new int[numOfComputers][numOfComputers - 1];
                slots = new int[numOfComputers];
                for (int i = 0; i < numOfComputers - 1; i++) {
                    do {
                        line = br.readLine();
                    } while (line == null || line.equals(""));
                    st = new StringTokenizer(line, " ");
                    int comp1 = Integer.parseInt(st.nextToken());
                    int comp2 = Integer.parseInt(st.nextToken());
                    if (comp1 >= nodes.length || comp2 >= nodes.length) {
                        System.out.println(0);
                        continue;
                    }
                    nodes[comp1][slots[comp1]++] = comp2;
                    nodes[comp2][slots[comp2]++] = comp1;
                }

                getAnswer();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private Main_old() {
        //readData();
        loadWithScanner();
    }

    public static void main(String[] args) {
        new Main_old();
    }

    public void loadWithScanner() {
        Scanner sc  = new Scanner(System.in);
        int numOfCases = sc.nextInt();
        while(numOfCases-- != 0) {
            int numOfComputers = sc.nextInt();
            nodes = new int[numOfComputers][numOfComputers - 1];
            slots = new int[numOfComputers];
            for (int i = 0; i < numOfComputers- 1; i++) {
                int comp1 = sc.nextInt();
                int comp2 = sc.nextInt();

                nodes[comp1][slots[comp1]++] = comp2;
                nodes[comp2][slots[comp2]++] = comp1;

            }

            getAnswer();
        }
    }
}
