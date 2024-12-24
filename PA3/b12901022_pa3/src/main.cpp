// #include "../lib/tm_usage.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include "./cb.h"
using namespace std;

void help_message() { cout << "please check proper usage"; }

int main(int argc, char *argv[]) {
  if (argc != 3) {
    help_message();
    return 0;
  }
  // CommonNs::TmUsage tmusg;
  // CommonNs::TmStat stat;

  //////////// read the input file /////////////

  // char buffer[200];
  fstream fin(argv[1]);
  // fstream fin;
  // fin.open(argv[1]);
  fstream fout;
  fout.open(argv[2], ios::out);
  // fin.getline(buffer, 200);
  // fin.getline(buffer, 200);
  char c;
  int n, m;
  fin >> c >> n >> m;
  CB cb;
  cb.init(c, n, m);
  for(int i = 0; i < m; i++) {
    int a, b, w;
    fin >> a >> b >> w;
    cb.add(a, b, w);
  }
  fin >> n;
  if(n != 0){
    cout << "input error!\n";
    return 0;
  }


  //////////// main part ////////////////
  cb.solve();
  cb.print(fout);
  // tmusg.periodStart();
  // mps.print(fout);
  // tmusg.getPeriodUsage(stat);
  // cout << "The total CPU time: " << (stat.uTime + stat.sTime) / 1000.0 << "ms"
  //      << endl;
  // cout << "memory: " << stat.vmPeak << "KB" << endl; // print peak memory

  //////////// write the output file ///////////
  // fout << "# " << data.size() << " data points" << endl;
  // fout << "# index number" << endl;
  // for (int i = 0; i < data.size(); i++)
  //   fout << i << " " << data[i] << endl;
  fin.close();
  fout.close();
  return 0;
}

