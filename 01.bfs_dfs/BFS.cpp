#include <iostream>
#include <list>
#include <queue>
#include <map>
using namespace std;

class GraphStructure {
public:
    map<int, list<int>> adjacencyList;
    map<int, bool> visitedNodes;

    void addEdge(int node1, int node2);
    void BFS(int startNode);
};

void GraphStructure::addEdge(int node1, int node2) {
    adjacencyList[node1].push_back(node2);
}

void GraphStructure::BFS(int startNode) {
    queue<int> nodeQueue;  // Use queue for BFS

    visitedNodes[startNode] = true;
    nodeQueue.push(startNode);

    while (!nodeQueue.empty()) {
        int currentNode = nodeQueue.front();
        nodeQueue.pop();

        cout << currentNode << " ";

        for (auto neighbor : adjacencyList[currentNode]) {
            if (!visitedNodes[neighbor]) {
                visitedNodes[neighbor] = true;
                nodeQueue.push(neighbor);
            }
        }
    }
}

int main() {
    GraphStructure graph;
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 7);
    graph.addEdge(4, 5);
    graph.addEdge(4, 6);

    cout << "Breadth First Traversal of 1st graph: ";
    graph.BFS(1);

    return 0;
}
