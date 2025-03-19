#include "Maze.hpp"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

Maze::Maze(int n){
    this->n = n; 
     // cout << "maze " << endl;
}

void Maze::addEdge(int v1, int v2){
    // add code here 
    // cout << " add edge" << endl;
    vertex *vert1,*vert2;
    for(int i = 0; i < vertices.size(); i++){ // getting verts that correspond to v1 v2
        if(vertices[i]->num == v1){
            vert1 = vertices[i];
        }
        if(vertices[i]->num == v2){
            vert2 = vertices[i];
        }
    }
    bool edgeExists = false;
    for(int i=0;i < vert1->adj.size();i++){ 
        if(vert1->adj[i].v->num == vert2->num){ // see if there already exists an edge
            edgeExists = true;
        }
    }
    if(edgeExists == false){ // if no edge exists create
        adjVertex newAdjV, anewadjv;
        newAdjV.v = vert1;
        anewadjv.v = vert2;
        vert1->adj.push_back(anewadjv);
        vert2->adj.push_back(newAdjV);
    }
}

void Maze::addVertex(int num){
    // add code here
    // cout << " addvert" << endl;
    vertex *vert1 = new vertex;
    vert1->num = num;
    vert1->visited = false;
    bool exists = false;
    for(int i=0;i<vertices.size();i++){
        if(vertices[i]->num == num){
            exists = true;
        }
    }
    if(exists == false){
        vertices.push_back(vert1);
    }
}

void Maze::displayEdges(){
    // add code here 
    // cout << " display" << endl;
    cout << endl;
    cout << "Adjacency List Graph:" << endl;
    for(int i=0;i<vertices.size();i++){
        cout << vertices[i]->num << " --> ";
        for(int x=0; x<vertices[i]->adj.size();x++){
            cout << vertices[i]->adj[x].v->num << " ";
        }
        cout << endl;
    }
}

int Maze::findVertexNumFromPosition(int x, int y){
    // add code here 
    return y+x*n;
}

// Creates a default maze of all 1s of size n x n, except for positions (0,0) and (n-1, n-1)
void Maze::createDefaultMaze(){
    // cout << " defaultmaze" << endl;
    cout << "Maze of size (" << n << "x" << n << ")" << endl;
    maze = new int*[n];
    for(int i=0;i<n;i++){
        maze[i] = new int[n];

        for(int x=0;x<n;x++){
            maze[i][x] = 1;
        }
    }
    maze[0][0] = 0;
    maze[n-1][n-1] = 0;
}

void Maze::createPath(int i, int j){
    // add code here
    // cout << " create path" << endl;
    maze[i][j] = 0;
}

void Maze::printMaze(){
    // cout << " print maze" << endl;
    for(int i=0;i<n;i++){
        for(int x=0;x<n;x++){
            cout << "| "<< maze[i][x] << " ";
        }
        cout << "|" << endl;
    }
}

vector<int> Maze::findOpenAdjacentPaths(int x, int y){
    // identify the open paths that are adjacent to the vertex at x, y
    // fill adjArr array with the numbers of the adjacent vertices
    vector<int> neighbors; 
    for(int i = x-1; i <= x + 1; i++){
        if(i < 0 || i >= n){
            continue;
        }
        for(int j = y-1; j <= y+1; j++){
            if(j < 0 || j >= n){
                continue;
            }
            // if there is an open path at this adjacent position, add to adjArray
            if(!(i == x && j == y) && maze[i][j] == 0){
                neighbors.push_back(findVertexNumFromPosition(i, j));
            }
        }
    }
    return neighbors;
}

void Maze::convertMazeToAdjacencyListGraph(){
    // add all the vertices to the adjacency list
    // add all edges to the adjacency list
    for(int i=0;i<n;i++){
        for(int x=0;x<n;x++){
            if(maze[i][x] == 0){
                addVertex(findVertexNumFromPosition(i, x)); // added this node to vertices
            }
        }
    }
    for(int w=0;w<vertices.size();w++){
        int x = vertices[w]->num / n; // int divide by int, gives us row num;
        int y = vertices[w]->num - (x * n);
        vector<int> adjToOpenVert = findOpenAdjacentPaths(x,y);
        for(int l=0;l<adjToOpenVert.size();l++){
            addEdge(findVertexNumFromPosition(x,y), adjToOpenVert[l]);
        }
    }
}

bool DFTraversal(vertex *n, vector<int> &path, int finalkey, bool poopoo)
{
    cout << "Reached vertex: " << n->num << endl; 
    path.push_back(n->num);
    if(n->num == finalkey){
        return true;
    }
    n->visited = true;
    for(int x = 0; x < n->adj.size(); x++ ){   
        if(n->adj[x].v->visited == false){
            poopoo = DFTraversal(n->adj[x].v, path, finalkey, poopoo);
        }
    }
    if(poopoo == false){
        path.pop_back();
        if(path.empty()){
            return false;
        }
        cout << "Backtracked to vertex: " << path.back() << endl;
    }
    return poopoo;
}

bool Maze::findPathThroughMaze(){
    cout << "Starting at vertex: 0" << endl; 
    bool poopoo = false;
    vertex *vert1;
    for(int x = 0; x < vertices.size(); x++){
        if(vertices[x]->num == 0){
            vert1 = vertices[x];
        }
    }
    int finalkey = n * n -1;
    return DFTraversal(vert1, path, finalkey, poopoo);
}


bool Maze::checkIfValidPath(){
    // add code here
    if(path[0] != 0 ){
        return false;
    }
    if(path.back() != (n * n -1)){
        return false;
    }
    for(int i =0;i<path.size()-1;i++){

        vertex *vert1;
        for(int x = 0; x < vertices.size(); x++){
            if(vertices[x]->num == path[i]){
                vert1 = vertices[x];
            }
        }
        bool found = false;
        for(int j=0;j<vert1->adj.size(); j++){
            if(vert1->adj[j].v->num == path[i+1]){
                found = true;
            }
        }
        if(found == false){
            return false;
        }

    }
    return true;
}

Maze::~Maze(){
    if (n > 0){
        for(int i = 0; i < n; i++){
            delete[] maze[i];
        }
        delete[] maze;
    }
    for (unsigned int i = 0; i< vertices.size(); i++){
        delete vertices[i]; 
    }
}
