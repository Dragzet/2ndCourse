#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) { //для сравнивания
        return weight < other.weight;
    }
};

class Graph {
private:
    int V; // количество вершин
    vector<Edge> edges; // список рёбер

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    // Поиск вершины в множествах
    int findSet(int v, vector<int>& parent) {
        if (v == parent[v]) return v;
        return parent[v] = findSet(parent[v], parent);
    }

    // добавляем вершину между 2 множествами без цикла (пересекаем)
    void unionSets(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = findSet(a, parent);
        b = findSet(b, parent);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    //Основная идея - шаг за шагом накидывать ребра с мин весом, пока не получится так, что все вершины соединены
    void kruskalMST() {
        sort(edges.begin(), edges.end()); // Сортируем рёбра по возрастанию веса

        vector<int> parent(V);
        vector<int> rank(V, 0);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        vector<Edge> result;
        int cost = 0;

        for (Edge e : edges) {
            if (findSet(e.u, parent) != findSet(e.v, parent)) {
                cost += e.weight;
                result.push_back(e);
                unionSets(e.u, e.v, parent, rank);
            }
        }

        cout << "Minimal ost tree: " << endl;
        for (Edge e : result) {
            cout << e.u + 1 << " - " << e.v + 1 << " : " << e.weight << endl;
        }
        cout << "Whole: " << cost << endl;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(1, 2, 1);
    g.addEdge(1, 5, 10);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 5, 6);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 5, 7);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 5, 11);

    g.kruskalMST(); 

    return 0;
}
