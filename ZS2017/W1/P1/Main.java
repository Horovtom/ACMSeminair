package P1;

import java.util.*;
import java.lang.*;

class Main
{

    Stack<Integer> S = new Stack<>();
    boolean[] discovered;
    Node[] nodes;


    public boolean getAnswer() {
        //dfs
        discovered = new boolean[nodes.length];
        return dfs(1);
    }

    private boolean dfs(int v) {
        S.push(v);
        while(S.size() != 0) {
            v = S.pop();
            if (!discovered[v]) {
                discovered[v] = true;
                for (int i = 0; i < nodes[v].neighbours.size(); i++) {
                    S.push(nodes[v].neighbours.get(i));
                }
            } else {
                return false;
            }
        }
        for (int i = 1; i < discovered.length; i++) {
            if (!discovered[i]) return false;
        }
        return true;
    }

    private class Node {
        ArrayList<Integer> neighbours = new ArrayList<>();
    }


    public static void main (String[] args) throws java.lang.Exception {
        Main m = new Main();
        if (!m.loadData()) return;
        boolean res = m.getAnswer();
        System.out.println(res ? "YES" : "NO");
    }

    private boolean loadData() {
        Scanner sc = new Scanner(System.in);
        int nodes = sc.nextInt();
        int edges = sc.nextInt();
        if (edges != nodes - 1) {
            System.out.println("NO");
            return false;
        }
        this.nodes = new Node[nodes + 1];


        while(edges-- > 0) {
            int node = sc.nextInt();
            int node2  = sc.nextInt();
            //System.out.println("There is an edge between " + node + " and " + node2);
            if (this.nodes[node] == null ) this.nodes[node] = new Node();
            if (this.nodes[node2] == null) this.nodes[node2] = new Node();

            this.nodes[node].neighbours.add(node2);
        }

        return true;
    }
}