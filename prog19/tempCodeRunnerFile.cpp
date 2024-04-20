class Graph {
public:
    int vertices;
    vector<int> parent;
    vector<vector<int>> adjacencyList;

    Graph(int V) : vertices(V), parent(V, -1), adjacencyList(V) {} // Initialize parent and adjacencyList

    int find(int v) {
        if (parent[v] == -1) // Check for self-parent (-1)
            return v;
        return find(parent[v]);
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        parent[rootX] = rootY;
    }

    bool isCyclic() {
        for (int u = 0; u < vertices; ++u) {
            for (int v : adjacencyList[u]) {
                int rootU = find(u);
                int rootV = find(v);

                if (rootU == rootV)
                    return true;

                unionSets(rootU, rootV);
            }
        }

        return false;
    }

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); // Add edge in both directions for undirected graph
    }
};