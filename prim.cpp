#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std; 

int minIncident(vector< vector<int> > edgeSet, int vert, int e);

int main(){

	ifstream infile("exampleWG.txt");//opening text file

	//error handleing
	if(!infile){

		cout<<"file could not be opened."<<endl;
	} 

	int vert, e, edge; 

	infile >> vert; // Reads in the number of vertices. 
	infile >> e; // Reads in the number of edges. 

    // Check that the order of the graph is correct
    cout <<"The order of the graph is "<< vert << endl;

	// Check that the size of the graph is correct
    cout <<"The size of the graph is " <<  e << endl;

    vector <vector<int> > edgeSet;// 2-D vector that stores the edges
  	// [[row 1], [row 2], ..., [row m]]
	

	for(int i =0; i < vert; i++){
		vector<int> row; 
			for(int j = 0; j < 3; j++){
				row.push_back(edge); //add a new element to the vector each time a new integer is read
			}

			edgeSet.push_back(row);// adds row to the vector
		}


	
	vector <int> treeVert; // vertex of tree
	vector <vector<int>> treeSet; // the edge set of the tree

	int edge1 = minIncident(edgeSet, treeVert[0], e);

	treeVert.push_back(0);// initialize vertex set of tree to 0
	treeSet.push_back(edgeSet[edge1]);

	int vertex = addVertex(edgeSet, treeSet, treeVert); 
	treeSet.push_back(vertex);

	for(int i = 0; i<treeSet.size(); i++){
		cout<< treeSet[i]<<endl; 
	}

	
	return 0; 

}