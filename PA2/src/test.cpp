#include "mps.h"
#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;
  MPS mps(n);
  cout << mps.size << '\n';
  for(int i = 0; i < n / 2; i++){
    int a, b; cin >> a >> b;
    mps.add(a, b);
  }
  for(int i = 0; i < mps.size; i++){
    cout << mps.adj[i] << ' ';
  }
  cout << '\n';
  mps.run_dp();
  mps.print();
  return 0;
}
