#include "mps.h"
#include <algorithm>
#include <iostream>

MPS::MPS(int n) {
  size =  n;
  adj = new int[size];
  dp_table = new int*[size];
  for(int i = 0; i < size; i++){
    // dp_table[i] = new int[i + 1];
    dp_table[i] = new int[size];
  }
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++) dp_table[i][j] = -1;
  }
}

void MPS::add(int a, int b) {
  adj[a] = b;
  adj[b] = a;
}

int MPS::calc(int i, int j){
  // if(i >= j) return 0;
  if(dp_table[i][j] != -1) return dp_table[i][j];
  if(i == j){
    dp_table[i][j] = 0;
    return dp_table[i][j];
  }
  int connected_point = adj[j];
  if(connected_point > j || connected_point < i){
    dp_table[i][j] = calc(i, j - 1);
    return dp_table[i][j];
  }
  else{
    if(connected_point == i){
      dp_table[i][j] = calc(i + 1, j - 1) + 1;
      return dp_table[i][j];
    }
    else{
      dp_table[i][j] = std::max(calc(i, j - 1), calc(i, connected_point - 1) + calc(connected_point + 1, j) + 1);
      return dp_table[i][j];
    }
  }
}

int MPS::run_dp(){
  return calc(0, size - 1);
}

void MPS::find_prt(int i, int j){
  if(i == j) return;
  int connected_point = adj[j];
  if(connected_point > j || connected_point < i){
    find_prt(i, j - 1);
  }
  else{
    if(connected_point == i){
      answer.push_back(i);
      find_prt(i + 1, j - 1);
    }
    else{
      if(dp_table[i][j] == dp_table[i][j - 1]){
        find_prt(i, j - 1);
      }
      else{
        answer.push_back(connected_point);
        find_prt(i, connected_point - 1);
        find_prt(connected_point + 1, j - 1);
      }
    }
  }
}

void MPS::print(std::fstream &fout){
  int ans = run_dp();
  find_prt(0, size - 1);
  std::cout << ans << std::endl;
  std::cout << answer.size() << std::endl;
  fout << ans << std::endl;
  sort(answer.begin(), answer.end());
  for(int i = 0; i < answer.size(); i++){
    std::cout << answer[i] << ' ' << adj[answer[i]] << std::endl;
    fout << answer[i] << ' ' << adj[answer[i]] << std::endl;
  }
}

MPS::~MPS() {
  for(int i = 0; i < size; i++){
    delete[] dp_table[i];
  }
  delete[] dp_table;
  for(int i = 0; i < size; i++){
  }
  delete[] adj;
}
