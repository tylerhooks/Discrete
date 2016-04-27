#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "prim.h"

using namespace std;

int minIncident(vector< vector<int> > edgeSet, int , int m){
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

 index = edge[index];
 return index; 
}
int addVertex(vector<vector<int> >edgeSet, vector<vector<int> > T, vector<int> VH){
  int addVertex;
  int dontAdd = VH[0];

  if(dontAdd == T[0][0]){
    addVertex = T[0][1];
  }
  else if(dontAdd == T[0][1]){
      addVertex = T[0][0];
  }


  return addVertex;
}
int minIncidentSet(vector<vector<int> > edgeSet, vector<int> VH, int m){

	vector <int> edge;
  int index = 0;
  int cost;
  
  for(int j = 0; j < VH.size();j++)
  {
    for(int i = 0; i < m; i++)
    {
      /*cout << "VH[ " << j <<" ] == edgeSet[" << i<< " ][0] && VH[j] != edgeSet[i][1]" << endl;*/
      if((VH[j] == edgeSet[i][0] && VH[j] != edgeSet[i][1]) ||
     (VH[j] != edgeSet[i][0] && VH[j] == edgeSet[i][1]))
    {
      edge.push_back(i);
    }
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
 index = edge[index];
 return index; 
}