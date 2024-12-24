#include "./cb.h"
#include "./dsu.h"
#include <iostream>
#include <algorithm>

void CB::init(char c, int n, int m) {
  // verex_count = n;
  // edge_count = m;
  graph_type = c;
  ans.resize(n);
  total_weight = 0;
  remain_weight = 0;
}

void CB::add(int a, int b, int w) {
  total_weight += w;
  edges.push_back(std::make_pair(w, make_pair(a, b)));
}

bool dfs(vector<vector<int> > &ans, bool *vstd, int b, int a) {
  vstd[b] = true;
  for(int i : ans[b]) {
    if(i == a) {
      return true;
    } else if(vstd[i]) {
      continue;
    } else {
      if(dfs(ans, vstd, i, a)) {
        return true;
      }
    }
  }
  return false;
}

bool CB::check_loop(int a, int b) {
  bool vstd[ans.size()];
  for(int i = 0; i < ans.size(); i++) {
    vstd[i] = false;
  }
  return dfs(ans, vstd, b, a);
}

bool comp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
  return a.first < b.first;
}

void CB::kruskal() {
  DSU dsu(ans.size());
  sort(edges.begin(), edges.end());
  int count = 0;
  for(int i = edges.size() - 1; i >= 0; i--) {
    int a = edges[i].second.first;
    int b = edges[i].second.second;
    if(dsu.same(a, b)) {
      continue;
    } else {
      dsu.merge(a, b);
      ans[a].push_back(b);
      // if(graph_type == 'u') {
      //   ans[edges[i].second.second].push_back(edges[i].second.first);
      // }
      remain_weight += edges[i].first;
      count++;
      edges[i].first = -200;
    }
  }
  if(count != ans.size() - 1) {
    cout << "error";
  }
}

void CB::solve() {
  kruskal();
  if(graph_type == 'u'){
    return;
  }
  for(int i = edges.size() - 1; i >= 0; i--) {
    if(edges[i].first <= 0) continue;
    int a = edges[i].second.first;
    int b = edges[i].second.second;
    if(!check_loop(a, b)) {
      ans[a].push_back(b);
      remain_weight += edges[i].first;
      edges[i].first = -200;
    }
  }
}

void CB::print(std::fstream &fout) {
  fout << total_weight - remain_weight << '\n';
  for(int i = edges.size() - 1; i >= 0; i--) {
    if(edges[i].first != -200) {
      fout << edges[i].second.first << ' ' << edges[i].second.second << ' ' << edges[i].first << '\n';
    }
  }
  std::cout << total_weight - remain_weight << '\n';
  for(int i = edges.size() - 1; i >= 0; i--) {
    if(edges[i].first != -200) {
      std::cout << edges[i].second.first << ' ' << edges[i].second.second << ' ' << edges[i].first << '\n';
    }
  }
}
