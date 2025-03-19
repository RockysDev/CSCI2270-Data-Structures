#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    std::vector<adjVertex> adj;
    bool visited = false;
    int distance = 0;
    bool solved = false;
    int distDijk = 0;
};

class Graph
{
    public:
        void addVertex(std::string name);
        void addEdge(std::string v1, std::string v2);
        void displayEdges();
        void resetGraph();
        void displayDistantNodes(std::string source_name); // TODO

    private:
        std::vector<vertex*> vertices;
        vertex* search(std::string sKey);
};

#endif // GRAPH_H