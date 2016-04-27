#include <iostream>
#include <fstream>
#include <vector>
#include "prim.h"
using namespace std;


int addVertex(vector< vector<int> > edgeSet, vector<int> VH, int row);
int minIncidentSet(vector< vector<int> > edgeSet, vector<int> VH, int m, bool []);
void checkIfTwice(vector<int> edges, bool arr[]);
void displayTree(vector< vector<int> > edgeSet, vector<int> T);

ifstream infile("exampleWG.txt");

int main() {
  
  int n; // Number of vertices.
  int m; // Number of edges.
 
  int edge;

  infile >> n; // Reads in the number of vertices.
  infile >> m; // Reads in the number of edges.
 
  // Check that the order of the graph is correct
  cout <<"The order of the graph is "<< n << endl;

  // Check that the size of the graph is correct
  cout <<"The size of the graph is " <<  m << endl << endl;

  /* 2-D vector that stores the edges
  [[row 1], [row 2], ..., [row m]]*/
  vector< vector<int> > edgeSet;

  for(int i = 0; i < m; i ++){
    vector<int> row; // The i-th row vector will be the i-th row of .txt

    for(int j = 0; j < 3; j++){
      infile >> edge;
      row.push_back(edge);
    }

    edgeSet.push_back(row); // Places row in the i-th entry of edgeSet
  }

  vector <int> VH; // VH is the vertex set of our tree
  
  vector<int> T; // T is the edge set of the tree

  bool *used = new bool[m];
  
  for(int i = 0; i < m; i++) {
    used[i] = false;
  }
  
  /* Initialize the vertex set of our tree (in this case vertex 0) */
  VH.push_back(0);
  int edges; // Min incident edge index to our initial vertex
  int vertex;
  
  while(VH.size() < n) {
    edges = minIncidentSet(edgeSet, VH, m, used);
    used[edges] = true;
    T.push_back(edges);
    vertex = addVertex(edgeSet, VH, edges);
    VH.push_back(vertex);
  }
  
  cout << endl;
  
  displayTree(edgeSet, T);
  
  delete [] used;
  
  return 0;
}


int minIncidentSet(vector<vector<int> > edgeSet, vector<int> VH, int m, bool used[]){

  vector <int> edge;
  int index = 0;
  int cost;
  
  for(int j = 0; j < VH.size();j++) {
    for(int i = 0; i < m; i++) {
      if(((VH[j] == edgeSet[i][0] && VH[j] != edgeSet[i][1]) ||
      (VH[j] != edgeSet[i][0] && VH[j] == edgeSet[i][1])) && !(used[i])) {
        edge.push_back(i);
      }
    }
  }

  bool *arr = new bool[edge.size()];
  
  for(int i = 0; i < edge.size(); i++) {
    arr[i] = false;
  }

  Prim p;
  p.checkIfTwice(edge, arr);
  
  cout << "The edges incident with VH are  " << endl;

  for(int i = 0; i < edge.size(); i++) {
    if(!(arr[i])) {
      cout << "edge " << edgeSet[edge[i]][0] << " " << edgeSet[edge[i]][1];
      cout << " with cost "<< edgeSet[edge[i]][2] << endl;
    }
  }

  cost = 10000000;

  for(int i = 0; i < edge.size(); i++) {
    if(edgeSet[edge[i]][2] < cost && !(arr[i])) {
      cost = edgeSet[edge[i]][2];
      index = i;
    }
  }

 cout << "Adding edge " << edge[index] << " with cost " << cost << endl;

 index = edge[index];

 return index;
}
int addVertex(vector<vector<int> > edgeSet, vector<int> VH, int row){

  for(int i = 0; i < VH.size(); i++) {
    if(VH[i] == edgeSet[row][0]) {
      return edgeSet[row][1];
    }
  }
  
  return edgeSet[row][0];
}

void checkIfTwice(vector<int> edges, bool arr[]) {
  for(int i = 0; i < edges.size() - 1; i++) {
    for(int j = 1; j < edges.size(); j++) {
      if(edges[i] == edges[j] && i != j) {
        arr[i] = true;
        arr[j] = true;
      }
    }
  }
}


void displayTree(vector< vector<int> > edgeSet, vector<int> T) {
  cout << "Minimum Weight Spanning Tree\n";
  
  int totalW = 0;
  
  for(int i = 0; i < T.size(); i++) {
    cout << "Edge " << edgeSet[T[i]][0] << " " << edgeSet[T[i]][1];
    cout << " with weight " << edgeSet[T[i]][2] << endl;
    totalW += edgeSet[T[i]][2];
  }
  
  cout << "The total weight of this spanning tree is " << totalW << ".\n";
}
