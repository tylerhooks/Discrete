#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "graphPack.h"

using namespace std;

 

//vector<int> edge_vw(vector<vector<int> >edgeSet, int i);

//int weight(vector<vector<int> > edgeSet, int i);

//vector<int> weightList(vector<vector<int> >edgeList, int m_list); 

//vector<vector<int> > min_edge(vector<vector<int> > edgeSet, vector<int> weightList);

//bool cycle(vector<int> F, vector<int> V_incident);

ifstream infile("exampleWG.txt");


int main(){
  
  int m;
  int m_list;
  int edge;

  infile >> m;
  m_list = m;

  vector <vector<int> > edgeSet;

  for(int i = 0; i < m_list; i ++){
    vector<int> row;

    for(int j = 0; j < 3; j++){
      infile >> edge;
      row.push_back(edge);
      //cout << row[j] << endl;
    }

    edgeSet.push_back(row);

  }

  /*for(int i = 0; i < 3; i++){
    cout<< edgeSet[5][i] << endl;
  }
  */


  /////////////////////////////////////////////////////////////////////////////////

 

  return 0;

}

