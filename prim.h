#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std; 

class Prim{

public:
	int minIncident(vector< vector<int> > edgeSet, int k, int m);
	int addVertex(vector<vector<int> >edgeSet, vector<vector<int> > T, vector<int> VH);
	int minIncidentSet(vector<vector<int> > edgeSet, vector<int> VH, int m);
}