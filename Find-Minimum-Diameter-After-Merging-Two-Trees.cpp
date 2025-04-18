class Solution {
public:
    int n;

    // Performs a Breadth-First Search to find the farthest node and its distance from the source
    pair<int, int> BFS(unordered_map<int, vector<int>>& adj, int source) {
        queue<int> que;
        que.push(source);

        unordered_map<int, bool> visited;
        visited[source] = true;

        int distance = 0;
        int farthestNode = source;

        while (!que.empty()) {
            int size = que.size(); // Nodes at the current level

            while (size--) {
                int curr = que.front();
                que.pop();

                farthestNode = curr; // Track the farthest node seen so far

                for (auto &nbr : adj[curr]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        que.push(nbr);
                    }
                }
            }
            // Increase distance after finishing each level
            if (!que.empty()) {
                distance++;
            }
        }

        return {farthestNode, distance};
    }

    // Finds the diameter (longest path) of a tree represented by its adjacency list
    int findDiameter(unordered_map<int, vector<int>> adj) {
        // Step 1: Find the farthest node from an arbitrary node (say node 0)
        auto [farthestNode, dist] = BFS(adj, 0);

        // Step 2: Run BFS again from the farthest node found above to get the diameter
        auto [otherEndNode, diameter] = BFS(adj, farthestNode);

        return diameter;
    }

    // Constructs an adjacency list from a list of edges
    unordered_map<int, vector<int>> buildAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Since the graph is undirected
        }

        return adj;
    }

    /**
     * Calculates the minimum diameter possible after merging two trees.
     * The idea is to connect their centers and compute the new possible diameter.
     */
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

        int d1 = findDiameter(adj1);  // Diameter of first tree
        int d2 = findDiameter(adj2);  // Diameter of second tree

        // The best way to merge is to connect centers of both trees
        int combined = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

        return max({d1, d2, combined});
    }
};
