#include <iostream>
#include <fstream>
#include "UnionFind.cpp"
using namespace std;
int main(int arg, char** argc) {
	//cout << argc[1] << endl;
	ifstream input(argc[1]);
	int N = 0; 
	input >> N;
	//if(!input.eof()) input >> N;
	//else throw std::invalid_argument("input file not properly formatted");
	UnionFind graph(2*N + 1);
    for(int i=0; i < N; i++) {
        int gi = 0; int bi = 0;
        input >> gi >> bi;
        graph.merge(gi, bi);
    }
    graph.print_sets();
	return 0;
}