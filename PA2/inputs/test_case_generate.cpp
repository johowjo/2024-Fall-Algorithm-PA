#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main(){
  fstream fout;
  fout.open("./180000.in");
  int n = 180000;
  fout << n << endl;
  vector<int> v(n);
  for(int i = 0; i < n; i++) v[i] = i;
  shuffle(v.begin(), v.end(), default_random_engine(0));
  for(int i = 0; i < n / 2; i++){
    fout << v[2 * i] << ' ' << v[2 * i + 1] << endl;
  }
  fout << 0;
  fout.close();
  return 0;
}
