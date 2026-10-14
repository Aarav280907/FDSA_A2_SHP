/*A disaster relief team needs to inspect all buildings in a city after an earthquake. The city is mapped as a network where
buildings are connected by roads. One team starts at a building and goes as deep into each road as possible before backtracking,
while a second team spreads out level by level — first checking all buildings directly connected to the start, then all buildings
two roads away, and so on. Given the city map as a graph and a starting building, implement both exploration strategies and print
the order in which buildings are visited by each team.*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class CityMap {
private:
    int n;                       // number of buildings (0 .. n-1)
    vector<vector<int>> adj;     // adjacency list

    void dfsHelper(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";
        for (int v : adj[u])
            if (!visited[v]) dfsHelper(v, visited);   // go deeper before backtracking
    }

public:
    CityMap(int buildings) : n(buildings), adj(buildings) {}

    void addRoad(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);     // roads are two-way
    }

    // Recursive DFS (uses the call stack)
    void dfsRecursive(int start) {
        vector<bool> visited(n, false);
        dfsHelper(start, visited);
    }

    // Iterative DFS (uses our own stack, avoids deep recursion on huge maps)
    void dfsIterative(int start) {
        vector<bool> visited(n, false);
        stack<int> s;
        s.push(start);
        while (!s.empty()) {
            int u = s.top();
            s.pop();
            if (visited[u]) continue;
            visited[u] = true;
            cout << u << " ";
            for (int i = (int)adj[u].size() - 1; i >= 0; i--)   // reverse so order matches recursive DFS
                if (!visited[adj[u][i]]) s.push(adj[u][i]);
        }
    }

    // BFS (uses a queue, visits level by level)
    void bfs(int start) {
        vector<bool> visited(n, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;   // mark when queued so nobody is queued twice
                    q.push(v);
                }
            }
        }
    }

    // Supplementary: detect a cycle in the undirected graph (ignores edge to direct parent)
    bool hasCycleFrom(int u, int parent, vector<bool>& visited) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                if (hasCycleFrom(v, u, visited)) return true;
            } else if (v != parent) {
                return true;     // reached an already-visited node that is not our parent
            }
        }
        return false;
    }

    bool hasCycle() {
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
            if (!visited[i] && hasCycleFrom(i, -1, visited)) return true;
        return false;
    }

    int size() const { return n; }
};

int main() {
    int n, e;
    cout << "Enter number of buildings: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid number of buildings." << endl;
        return 0;
    }
    cout << "Enter number of roads: ";
    cin >> e;

    CityMap city(n);
    cout << "Enter each road as two building numbers (0 to " << n - 1 << "):" << endl;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        if (a < 0 || a >= n || b < 0 || b >= n) {
            cout << "Invalid road, skipped." << endl;
            continue;
        }
        city.addRoad(a, b);
    }

    int start;
    cout << "Enter starting building: ";
    cin >> start;
    if (start < 0 || start >= n) {
        cout << "Invalid starting building." << endl;
        return 0;
    }

    cout << "\nDFS (recursive) : ";
    city.dfsRecursive(start);
    cout << "\nDFS (iterative) : ";
    city.dfsIterative(start);
    cout << "\nBFS             : ";
    city.bfs(start);
    cout << "\n\nLoop in the map (cycle check): " << (city.hasCycle() ? "Yes" : "No") << endl;

    return 0;
}
