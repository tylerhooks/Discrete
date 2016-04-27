#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
//#include "graphPack.h"

using namespace std;


vector <int> minIncident(vector< vector<int> > edgeSet, int k, int m);

 

ifstream infile("exampleWG.txt");


int main(){
  
  int n;// Number of vertices.
  int m;// Number of edges.
 
  int m_list;
  int edge;

  infile >> n; // Reads in the number of vertices. 
  infile >> m; // Reads in the number of edges. 
 
  cout <<"The order of the graph is "<< n << endl;
  cout <<"The size of the graph is " <<  m << endl;


  m_list = m;

  vector <vector<int> > edgeSet;// 2-D vector that stores the edges
  // [[row 1], [row 2], ..., [row m]]

 

  for(int i = 0; i < m; i ++){
    vector<int> row; // The i-th row vector will be the i-th row of .txt

    for(int j = 0; j < 3; j++){
      infile >> edge;
      row.push_back(edge);
      //cout << row[j] << endl;
    }

    edgeSet.push_back(row);
  }

 

  int v = 0; // Initialize Prims at vertex 0
  vector <int> VH; // VH is the vertex set of our tree
  vector <int> T;


  VH.push_back(3); // Initialize the vertex set of our tree
  
  
  //cout << VH.size() << endl;
  vector <int> edge1;

  edge1 = minIncident(edgeSet, VH[0], m);

 


  /////////////////////////////////////////////////////////////////////////////////


  return 0;

}


vector <int> minIncident(vector<vector<int> > edgeSet, int k, int m){

  vector <int> edge;
  int index = 0;
  int cost;
  
 for(int i = 0; i < m; i++){
    if(k==edgeSet[i][0] || k == edgeSet[i][1]){
      edge.push_back(i);

     }
  }

  cout << "The edges incident with VH are  " << endl;


  for(int i = 0; i < edge.size(); i++){
    cout << "edge " << edgeSet[edge[i]][0] << " " <<edgeSet[edge[i]][1] << " with cost "<< edgeSet[edge[i]][2] << endl;
  }

  cost = edgeSet[edge[0]][2];


  for(int i = 1; i < edge.size(); i++){
    if(edgeSet[edge[i]][2] < cost){
      cost = edgeSet[edge[i]][2];
      index = i;
    }
  }


 cout <<"Edge " <<  edge[index] <<" with cost "<< cost << endl;

 // cout <<"We add vertex " << edgeSet[edge[index]][0]<< endl;

 

 return edge;
}

