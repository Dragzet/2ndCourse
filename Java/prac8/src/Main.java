import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[][] graph = {
                {0, 1, 0, 0, 1},
                {1, 0, 1, 0, 0},
                {0, 1, 0, 1, 0},
                {0, 0, 1, 0, 1},
                {1, 0, 0, 1, 0}
        };

        BFS bfs = new BFS(graph);
        try {
            bfs.bfs(0);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        int[] distances = bfs.getDistances();
        System.out.println("Минимальные расстояния: " + Arrays.toString(distances));

        bfs.shutdown();
    }
}