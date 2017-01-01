#include <cassert>
#include <vector>
#include <iostream>
using namespace std;
class UnionFind {
public:
    UnionFind(int n) {
        size = n;
        sets = new int[size];
        rank = new int[size];
        for(int i=0; i < size; i++) {
            sets[i] = i; rank[i] = 0;
        }
    }
    ~UnionFind() {
        delete [] sets;
        delete [] rank;
    }
    
    int find(int s) {
        assert(s >= 0 && s < size);
        vector<int> A;
        while(s != sets[s]) {
            A.push_back(s);
            s = sets[s];
        }
        //path compression
        for(int i=0; i < A.size(); i++) sets[A[i]] = s;
        return s;
    }
    bool merge(int s1, int s2) {
        assert(s1 >= 0 && s1 < size);
        assert(s2 >= 0 && s2 < size);
        int s1_rep = find(s1);
        int s2_rep = find(s2);
        if(s1_rep == s2_rep) return false;
        //union by rank
        if(rank[s1_rep] > rank[s2_rep]) {
            sets[s2_rep] = s1_rep;
        } else if(rank[s1_rep] < rank[s2_rep]) {
            sets[s1_rep] = s2_rep;
        } else {    //ranks are the same
            sets[s2_rep] = s1_rep;
            rank[s1_rep] += 1;
        }
        //union by rank, also keep track of smallest & largest
        return true;    
    }
    void print_sets() {
        for(int i=0; i < size; i++) cout << find(i) << " ";
        cout << endl;
    }
private:
    int size = 0;
    int* sets;  //store the parent of i at i
    int* rank;
};