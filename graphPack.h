#ifndef GRAPHPACK_H
#define GRAPHPACK_H

using namespace std;


class Graph{

public:
  vector<vector<int> > adjacency_graph;
  vector<int> d_seq;
  int order;
  int size;
  float avg_degree;
  int min_d;
  int max_d;
  int radius;
  int diameter;
  int residue_G;
  int alpha_G;
  int gamma_G;

};


//Each of these functions will print to the terminal

//degree function returns the degree of vertex i
int degree(vector<vector<int> > neighbors, int i);

//d_seq function returns a vector with all the degrees of G
vector<int> d_seq(vector<vector<int> > neighbors, int n);

//avg_d function returns the average degree of G
float avg_d(vector<int> d_seq, int n);

//size function returns the number of edges in G
int size(vector<int> d_seq, int n);

//max_d function returns the maximum degree of G
int max_d(vector<int> d_seq);

//mi_d function returns the minimum degree of G
int min_d(vector<int> d_seq, int n);

//residue_G function calculates the residue of G
int residue_G(vector<int> d_seq, int n);






#endif