#ifndef _MPS_H
#define _MPS_H
#include <vector>
#include <fstream>

class MPS {
public:
  int size;
  int *adj;
  int **dp_table;
  std::vector<int> answer;

  void add(int i, int j);
  int run_dp();
  void print(std::fstream &fout);
  void find_prt(int i, int j);
  MPS(int n);
  ~MPS();
private:
  int calc(int i, int j);
};

#endif
