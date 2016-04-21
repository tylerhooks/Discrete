#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "graphPack.h"

using namespace std;


int induced_deg(vector<vector<int> > neighbors, vector<int> S, int n);


//Read in the graph.txt file with the following:
ifstream infile("k_33.txt");


////////////////////Program that Executes Declared Functions//////////////////////


int main(){

//Initialize Graph class
Graph Graph1;

//Introduce int variables for the order and a graph edge
int n;
int edge; 
 
//Read the first entry from the graph.txt file
infile >> n;

//Specify the order of Graph1
Graph1.order = n;

//Check that the graph has the correct order
cout << "The order of the graph is " << Graph1.order << endl;

//Determine the size of the adjacency matrix (this will be used later)
int N = n*n;






////////////////We now read in the graph.txt file into a 2-d vector////////////////

vector <vector<int> > graph; // [[row_1], [row_2], ..., [row_n]]
 
for(int i = 0; i < n; i++){ 
   vector<int> row; 
   
   for(int j = 0; j < n; j++){ 
      infile >> edge; // Reads in the j-th row of the adjacency matrix
      row.push_back(edge); // Places entries from j-th row into vector row
   } 
  
   graph.push_back(row); // The vector "row" is stored in the i-th entry of graph
 }








/////////////////////////////////Find Neighbors////////////////////////////////

 vector <vector<int> > neighbors;// [[neighbors_0], [neighbors_1],...,[neighbors_n]]
 vector <vector<int> > non_neighbors;//[[non_neighbors_0],...,[non_neighbors_n]]


 for(int i = 0; i < graph.size(); i++){
   vector<int> adjacent;// Adjacency list
   vector<int> non_adjacent;// Non-Adjacency list
}
}