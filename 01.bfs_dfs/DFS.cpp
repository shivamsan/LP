#include<iostream>
#include<list>
#include<map>
using namespace std;

class GraphStructure {
    map<int, bool> visitedNodes;
    map<int, list<int>> adjacencyList;

public:
    void addEdge(int node1, int node2);
    void DFS(int startNode);
};

void GraphStructure::addEdge(int node1, int node2) {
    adjacencyList[node1].push_back(node2);
}

void GraphStructure::DFS(int startNode) {
    visitedNodes[startNode] = true;

    cout << startNode << " ";

    for(auto nextNode : adjacencyList[startNode]) {
        if (!visitedNodes[nextNode]) {
            DFS(nextNode);
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

    cout << "Depth First Traversal of 1st graph: ";
    graph.DFS(1);

    return 0;
}