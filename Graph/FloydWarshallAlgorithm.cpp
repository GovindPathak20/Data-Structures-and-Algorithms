// Floys Warshall Algorithm:
// The Floyd Warshall Algorithm is a dynamic programming algorithm used to find the shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles). It works by iteratively updating a distance matrix that represents the shortest path between pairs of vertices.
// The algorithm has a time complexity of O(V^3), where V is the number of vertices in the graph. It is particularly useful for dense graphs and can handle both directed and undirected graphs.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int V, E;
    cin >> V >> E;

    // Initialize the distance matrix with infinity
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    // Set the distance from each vertex to itself to 0
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }

    // Read the edges and update the distance matrix
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w; // For directed graph
        // dist[v][u] = w; // Uncomment this line for undirected graph
    }

    // Floyd Warshall Algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // For negative cycle detection (optional)
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected!" << endl;
            return 0;
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distance matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

// Input:
// 4 5
// 0 1 3
// 0 2 1
// 1 2 7
// 1 3 5
// 2 3 2

// Time Complexity: O(V^3)
// Space Complexity: O(V^2)