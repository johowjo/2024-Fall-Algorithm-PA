#ifndef _CB_H
#define _CB_H
#include <vector>
#include <set>
#include <fstream>

class CB {
public:
  char graph_type;
  int total_weight;
  int remain_weight;
  // int verex_count;
  // int edge_count;
  std::vector<std::vector<int> > ans;
  std::vector<std::pair<int, std::pair<int, int> > > edges;
  // std::set<std::pair<int, std::pair<int, int> >, std::greater<std::pair<int, std::pair<int, int> > > > edges;

  void init(char c, int n, int m);
  void add(int a, int b, int w);
  void solve();
  void print(std::fstream &fout);
  void kruskal();
  bool check_loop(int a, int b);
};
#endif
