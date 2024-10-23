import java.util.*;
import java.util.concurrent.*;

public class BFS {
    private static final int INF = Integer.MAX_VALUE;
    private final int[][] graph;
    private final int[] distance;
    private final boolean[] visited;
    private final ExecutorService executor;

    public BFS(int[][] graph) {
        this.graph = graph;
        int n = graph.length;
        this.distance = new int[n];
        this.visited = new boolean[n];
        Arrays.fill(distance, INF);
        this.executor = Executors.newCachedThreadPool();
    }

    public void bfs(int start) throws InterruptedException {
        distance[start] = 0;
        visited[start] = true;

        Queue<Integer> queue = new ConcurrentLinkedQueue<>();
        queue.offer(start);

        while (!queue.isEmpty()) {
            int current = queue.poll();
            List<Future<?>> futures = new ArrayList<>();

            for (int neighbor = 0; neighbor < graph[current].length; neighbor++) {
                if (graph[current][neighbor] != 0 && !visited[neighbor]) {
                    final int next = neighbor;
                    Future<?> future = executor.submit(() -> {
                        int newDist = distance[current] + graph[current][next];
                        synchronized (this) {
                            if (newDist < distance[next]) {
                                distance[next] = newDist;
                                queue.offer(next);
                                visited[next] = true;
                            }
                        }
                    });
                    futures.add(future);
                }
            }

            for (Future<?> future : futures) {
                try {
                    future.get();
                } catch (ExecutionException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }

    public int[] getDistances() {
        return distance;
    }

    public void shutdown() {
        executor.shutdown();
    }


}
