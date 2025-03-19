#include <iostream>
#include "Graph.hpp"

using namespace std;

int main(int argc, char** argv)
{
    // NOTE (1): Different order of appearance in answer is also acceptable
    // NOTE (2): Nodes' visited status is set to false before each run
    // NOTE (3): Nodes' distance is set to INT_MAX before each run

    // ------------- //
    //  TEST CASE 1  //
    // ------------- //
    Graph g1;
    g1.addVertex("A");    g1.addVertex("B");    g1.addVertex("C");    g1.addVertex("D");   
    g1.addVertex("E");    g1.addVertex("F");    g1.addVertex("G");    g1.addVertex("H");
    g1.addEdge("A","B");
    g1.addEdge("A","C");
    g1.addEdge("C","D");
    g1.addEdge("B","E");
    g1.addEdge("D","E");
    g1.addEdge("E","F");
    g1.addEdge("G","H");

    cout << endl << "[GRAPH 1: Adjacency List]" << endl;
    cout << "=========================" << endl;
    g1.displayEdges();

    // 1(a)
    g1.resetGraph();
    cout << "TEST 1(a): A" << endl << "-----------------" << endl;
    cout << "[GOT     ] ";
    g1.displayDistantNodes("A");
    cout << endl << "[EXPECTED] F" << endl;
    cout << "NOTE: Different order is accepted." << endl;

    // 1(b)
    g1.resetGraph();
    cout << endl << "TEST 1(b): E" << endl << "-----------------" << endl;
    cout << "[GOT     ] ";
    g1.displayDistantNodes("E");
    cout << endl << "[EXPECTED] A C" << endl;
    cout << "NOTE: Different order is accepted." << endl;

    // 1(c)
    g1.resetGraph();
    cout << endl << "TEST 1(c): G" << endl << "-----------------" << endl;
    cout << "[GOT     ] ";
    g1.displayDistantNodes("G");
    cout << endl << "[EXPECTED] H" << endl;
    cout << "NOTE: Different order is accepted." << endl;
    cout << endl;

    // ------------- //
    //  TEST CASE 2  //
    // ------------- //
    Graph g2;
    g2.addVertex("A");    g2.addVertex("B");    g2.addVertex("C");  
    g2.addEdge("A", "B");
    g2.addEdge("B", "C");
    g2.addEdge("C", "A");

    cout << endl << "[GRAPH 2: Adjacency List]" << endl;
    cout << "=========================" << endl;
    g2.displayEdges();

    // 2(a)
    g2.resetGraph();
    cout << "TEST 2(a): A" << endl << "-----------------" << endl;
    cout << "[GOT     ] ";
    g2.displayDistantNodes("A");
    cout << endl << "[EXPECTED] B C" << endl;
    cout << "NOTE: Different order is accepted." << endl;

    // 2(b)
    g2.resetGraph();
    cout << endl << "TEST 2(b): C" << endl << "-----------------" << endl;
    cout << "[GOT     ] ";
    g2.displayDistantNodes("C");
    cout << endl << "[EXPECTED] A B" << endl;
    cout << "NOTE: Different order is accepted." << endl;
    cout << endl;

    // ------------- //
    //  TEST CASE 3  //
    // ------------- //
    Graph g3;
    g3.addVertex("A");    g3.addVertex("B");    g3.addVertex("C");
    g3.addVertex("D");    g3.addVertex("E");    g3.addVertex("F");
    g3.addVertex("G");    g3.addVertex("H");    g3.addEdge("A","C");
    g3.addEdge("B","C");
    g3.addEdge("B","D");
    g3.addEdge("B","E");
    g3.addEdge("C","E");
    g3.addEdge("D","E");
    g3.addEdge("D","F");
    g3.addEdge("E","F");
    g3.addEdge("X","Y");
    g3.addEdge("Y","Z");
    g3.addEdge("Z","X");

    cout << endl << "[GRAPH 3: Adjacency List]" << endl;
    cout << "=========================" << endl;
    g3.displayEdges();

    // 3(a)
    g3.resetGraph();
    cout << "TEST 3(a): D" << endl << "-----------------" << endl;
    cout << "[GOT     ] ";
    g3.displayDistantNodes("D");
    cout << endl << "[EXPECTED] A" << endl;
    cout << "NOTE: Different order is accepted." << endl;

    // 3(b)
    g3.resetGraph();
    cout << endl << "TEST 3(b): B" << endl << "-----------------" << endl;
    cout << "[GOT     ] ";
    g3.displayDistantNodes("B");
    cout << endl << "[EXPECTED] A F" << endl;
    cout << "NOTE: Different order is accepted." << endl;

    // 3(c)
    g3.resetGraph();
    cout << endl << "TEST 3(c): A" << endl << "-----------------" << endl;
    cout << "[GOT     ] ";
    g3.displayDistantNodes("A");
    cout << endl << "[EXPECTED] D F" << endl;
    cout << "NOTE: Different order is accepted." << endl;
    cout << endl;

    // ------------- //
    //  TEST CASE 4  //
    // ------------- //
    Graph g4;
    g4.addVertex("A");    g4.addVertex("B");    g4.addVertex("C");
    g4.addVertex("D");    g4.addVertex("E");    g4.addVertex("F");
    g4.addVertex("G");    g4.addVertex("H");
    g4.addEdge("A","B");
    g4.addEdge("B","C");
    g4.addEdge("C","D");
    g4.addEdge("C","F");
    g4.addEdge("C","H");
    g4.addEdge("D","E");
    g4.addEdge("D","G");
    g4.addEdge("E","F");
    g4.addEdge("F","H");

    cout << endl << "[GRAPH 4: Adjacency List]" << endl;
    cout << "=========================" << endl;
    g4.displayEdges();

    // 4(a)
    g4.resetGraph();
    cout << "TEST 4(a): C" << endl << "-----------------" << endl;
    cout << "[GOT     ] ";
    g4.displayDistantNodes("C");
    cout << endl << "[EXPECTED] A E G" << endl;
    cout << "NOTE: Different order is accepted." << endl;

    // 4(b)
    g4.resetGraph();
    cout << endl << "TEST 4(b): A" << endl << "-----------------" << endl;
    cout << "[GOT     ] ";
    g4.displayDistantNodes("A");
    cout << endl << "[EXPECTED] E G" << endl;
    cout << "NOTE: Different order is accepted." << endl;

    // 4(c)
    g4.resetGraph();
    cout << endl << "TEST 4(c): F" << endl << "-----------------" << endl;
    cout << "[GOT     ] ";
    g4.displayDistantNodes("F");
    cout << endl << "[EXPECTED] A G" << endl;
    cout << "NOTE: Different order is accepted." << endl;

    return 0;
}