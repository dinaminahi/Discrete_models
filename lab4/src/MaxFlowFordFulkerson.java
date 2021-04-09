public class MaxFlowFordFulkerson {
    public static int maxFlow(int[][] cap, int s, int t) {
        for (int flow = 0; ; ) {
            int df = findPath(cap, new boolean[cap.length], s, t, Integer.MAX_VALUE);
            if (df == 0) {
                System.out.println();
                System.out.print("Макимальна сума: ");
                return flow;
            }

            flow += df;
        }
    }

    static int findPath(int[][] cap, boolean[] vis, int u, int t, int f) {
        if (u == t) {

            System.out.println("Кінець шляху, передали: " + f);
            return f;
        }

        vis[u] = true;
        for (int v = 0; v < vis.length; v++)
            if (!vis[v] && cap[u][v] > 0) {
                int df = findPath(cap, vis, v, t, Math.min(f, cap[u][v]));
                if (df > 0) {
                    cap[u][v] -= df;
                    System.out.println(u + " -> " + v + ": " + cap[u][v]);
                    cap[v][u] += df;
                    System.out.println(u + " <- " + v + ": " + cap[v][u]);
                    return df;
                }
            }
        return 0;
    }

    // Usage example
    public static void main(String[] args) {
        try {
            int[][] graph = MainLogic.create2DIntMatrixFromFile("src\\files\\matrix");
            System.out.println(maxFlow(graph, 0, 5));
        } catch (Exception e) {

        }
    }
}


  /*      int graph[][] = new int[][]{
                {0, 16, 13, 0, 0, 0},
                {0, 0, 10, 12, 0, 0},
                {0, 4, 0, 0, 14, 0},
                {0, 0, 9, 0, 0, 20},
                {0, 0, 0, 7, 0, 4},
                {0, 0, 0, 0, 0, 0}
        };*/