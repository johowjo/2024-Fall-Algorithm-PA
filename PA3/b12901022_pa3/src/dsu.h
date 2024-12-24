#ifndef _DSU_H
#define _DSU_H
#include <vector>
#define pb push_back
using namespace std;
class DSU{
public:
  vector<int> prt;
  vector<int> rank;

  DSU(int n){
    prt.clear();
    rank.clear();
    for(int i = 0; i < n; i++){
      prt.pb(i);
    }
    rank.assign(n, 0);
  }

  int find(int x){
    int y = x;
    while(y != prt[y]){
      y = prt[y];
    }
    int z = x;
    while(z != prt[z]){
      int w = z;
      prt[z] = y;
      z = prt[w];
    }
    return y;
  }

  void merge(int a, int b){
    int aa = find(a);
    int bb = find(b);
    if(aa == bb) return;
    if(rank[aa] > rank[bb]) swap(aa, bb);
    prt[aa] = bb;
    if(rank[aa] == rank[bb]) rank[bb]++;
  }

  bool same(int a, int b){
    return find(a) == find(b);
  }
};
#endif
